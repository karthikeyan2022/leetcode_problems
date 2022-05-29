/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
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
#define MODE RECUR

class Solution {
public:

    struct node
    {
        bool isWord;
        struct node* children[26];
        string s;
    };
    
    vector<string> retVect;
    struct node root;
    struct node nodepool[1000*20];
    int nodepoolcnt = 0;
    
    void trie_init()
    {
        nodepoolcnt = 0;
        root.isWord = false;
        root.s = "";
        for(int i = 0; i < 26; i++)
        {
            root.children[i] = 0;
        }
    }
    
    struct node* getnewnode()
    {
        struct node* nnode = &nodepool[nodepoolcnt++];
        
        nnode->isWord = false;
        nnode->s.clear();
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
            
            curr = curr->children[pos];
            c++;
        }
        
        curr->s = s;
        curr->isWord = true;
    }

  
    // RECURSION passed
 #if(MODE== RECUR)   
    bool doRecursive(string s, int idx, struct node* curr, vector<string> strlist)
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
                    strlist.push_back(temp->s);

                    string temp;

                    for(int i = 0; i < strlist.size(); i++)
                    {
                        temp.append(strlist[i]);

                        if(i != strlist.size()-1)
                            temp.append(" ");
                    }

                    retVect.push_back(temp);
                    return true;
                }    
                else
                    return false;
            }

            // if word is found go to two branches - i) continue ii) start node from root
            if(temp->isWord)
            {
                
                // if word is found
                strlist.push_back(temp->s);
                ret = doRecursive(s, idx+1, &root,strlist);
                strlist.pop_back();
                

                // considering it is not a word
                ret = doRecursive(s, idx+1, temp,strlist);     
            }
            else
            {
                ret = doRecursive(s, idx+1, temp,strlist);
            }    
        }
       
        return ret; 
    }

#endif

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        vector<string> stringlist;
        trie_init();  
        int len = s.size(); 
        for(int i = 0; i < wordDict.size(); i++)
            trie_insert(wordDict[i]);

        doRecursive(s, 0, &root, stringlist);

        return retVect;
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
    vector<string> listofwords = sol->wordBreak(s, dict);
}
#endif
// @lc code=end

