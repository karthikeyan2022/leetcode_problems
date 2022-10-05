/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 */

// @lc code=start
class Solution {
public:
    struct node
    {
        string str;
        struct node* children[26];
        bool bisword;
    };
    
    struct node nodepool[1000*31];
    int nodepoolcnt = 0;
    
    struct node root;
    
    void trie_init()
    {
        nodepoolcnt = 0;
        root.str = "";
        root.bisword = false;
        for(int i = 0; i < 26; i++)
            root.children[i] = 0;
    }
    
    struct node* getnewnode()
    {
        struct node* nnode = &nodepool[nodepoolcnt++];
        
        nnode->bisword = false;
        nnode->str = "";
        for(int i = 0; i < 26; i++)
            nnode->children[i] = 0;
    
        return nnode;
    }
    
    string getSmallLexi(string s1, string s2)
    {
        int len1 = s1.size();
       
        for(int i = 0; i < len1; i++)
        {
            if(s1[i] < s2[i])
            {
                return s1;
            }
            else if(s1[i] > s2[i])
            {
                return s2;
            }
        }
        return s1;
    }

    string longestWord(vector<string>& words) {
         int len = words.size();
        int maxVal = 0;
        string maxStr = "";
        struct node* curr = 0;
        int pos = 0;
        
        // just insert into trie
        for(int i = 0; i < len; i++)
        {
            string s = words[i];  
            int slen = s.size();
            curr = &root;
            
            for(int j = 0; j < slen; j++)
            {
                pos = s[j] - 'a';
                
                if(curr->children[pos] == 0)
                {
                    curr->children[pos] = getnewnode();
                }
                
                curr = curr->children[pos];
            }
            
            curr->bisword = true;
        }
        
        bool bstop = false;
        // calculate max with check array
        for(int i = 0; i < len; i++)
        {
            string s = words[i];
            
            int slen = s.size();
            curr = &root;
            
            bstop = false;
            vector<bool> check(slen+1,0);
            int j = 0;
            for( j = 0; j < slen; j++)
            {
                pos = s[j] - 'a';
                
                if(curr->bisword)
                {
                    check[j] = 1;
                }
                else if(j != 0) // isword from j = 1. curr root ignore
                {
                    bstop = true;
                    break;
                }     
                curr = curr->children[pos];
            }

            if(bstop)
                continue;
              
            if(slen >= maxVal)
            {
                // cout << slen << endl;
                // cout << s << endl;
                
                // for(int a: check)
                //     cout << a << " ";
                // cout << endl;
                
                if(slen == maxVal)
                    maxStr = getSmallLexi(maxStr, s);
                else
                    maxStr = s;
                
                maxVal = slen;
            }
            
        }
        
        return maxStr;
    }
};
// @lc code=end

