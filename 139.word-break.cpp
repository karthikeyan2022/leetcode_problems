/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start

#define DEBUG 0

#if(DEBUG)
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#endif

#define RECUR   0
#define DP 1
#define MODE DP
class Solution {
public:
    struct node
    {
        bool isWord;
        struct node* children[26];
    };
    
    struct node root;
    struct node nodepool[1000*20];
    int nodepoolcnt = 0;
    bool done = false;
    
    int count[26] = {0};

    void trie_init()
    {
        nodepoolcnt = 0;
        root.isWord = false;
        for(int i = 0; i < 26; i++)
        {
            root.children[i] = 0;
        }
    }
    
    struct node* getnewnode()
    {
        struct node* nnode = &nodepool[nodepoolcnt++];
        
        nnode->isWord = false;
        for(int i = 0; i < 26; i++)
        {
            nnode->children[i] = 0;
        }
        
        return nnode;
    }
    
    void trie_insert(string s)
    {
        int c = 0;
        struct node* curr = &root;
        int pos;
        while(s[c] != '\0')
        {
            pos = s[c] - 'a';
            
            if(curr->children[pos] == 0)
            {
                curr->children[pos] = getnewnode();
            }
            
            count[pos]++;
            curr = curr->children[pos];
            c++;
        }
        
        curr->isWord = true;
    }

    bool trie_find(string s)
    {
        int c = 0;
        struct node* curr = &root;
        int pos;
        while(s[c] != '\0')
        {
            pos = s[c] - 'a';
            
            if(curr->children[pos] == 0)
            {
                return false;
            }
            
            curr = curr->children[pos];
            c++;
        }
        
        return (curr->isWord);
    }
    
    // RECURSION GIVES TLE. BUT LOGICALLY CORRECT!!!
 #if(MODE== RECUR)   
    bool doRecursive(string s, int idx, struct node* curr)
    {
        int ret = false;
        int pos = s[idx]-'a';
        
        if(curr && curr->children[pos])
        {
            struct node* temp = curr->children[pos];
            
            if(idx == (s.size()-1))
            {
                if(temp->isWord)
                {
                    return true;
                }    
                else
                    return false;
            }

            // if word is found go to two branches - i) continue ii) start node from root
            if(temp->isWord)
            {
                if(!ret)
                    ret = doRecursive(s, idx+1, &root);

                if(!ret)
                    ret = doRecursive(s, idx+1, temp);     
            }
            else
            {
                ret = doRecursive(s, idx+1, temp);
            }    
        }
       
        return ret; 
    }

#endif

    bool wordBreak(string s, vector<string>& wordDict) {
        
        trie_init();  
        int len = s.size(); 
        for(int i = 0; i < wordDict.size(); i++)
            trie_insert(wordDict[i]);
        
        for(int i = 0; i < s.size(); i++)
        {
            if(count[s[i]-'a'] == 0)
                return false;
        }

#if(MODE==RECUR)   
        return doRecursive(s, 0, &root);
#endif
        
        vector<bool> dp(len+1, false);

        dp[0] = true;// start dp set to true

        for(int i = 1; i <= len; i++)
        {
            for(int j = i-1; j >= 0; j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j, i-j);

                    if(trie_find(word))
                    {
                        dp[i] = 1;
                        break;
                    }

                }
            }
        }

        // for(bool a : dp)
        //     cout << a << " ";
        // cout << endl;

        return dp[len];

    } 
};

#if(DEBUG)
int main()
{
    class Solution* sol = new Solution();

   

//     "aaaaaaa"
// ["aaaa","aaa"]

    // string s = "aaaaaaa";
    // vector<string> dict = {"aaaa","aaa"};

    string s = "leetcode";
    vector<string> dict = {"leet","code"};
    bool val = sol->wordBreak(s, dict);
}
#endif
// @lc code=end

