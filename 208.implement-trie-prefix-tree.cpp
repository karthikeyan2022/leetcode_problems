/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start

struct TRIE
{
    char c;
    bool isWord;
    struct TRIE* children[26];
};

struct TRIE root;

class Trie {
public:
    Trie() {
        root.isWord = 0;
        for(int i = 0; i < 26; i++)
        {
            root.children[i] = 0;
        }
    }
    
    void insert(string word) {
        int c = 0;
        struct TRIE* curr = &root;
        int pos;
        while(word[c] != '\0')
        {
            pos = word[c] - 'a';
            
            if(curr->children[pos] == 0)
            {
                struct TRIE* new_node = new TRIE();
                new_node->c = word[c];
                curr->children[pos] = new_node;
            }
            
            curr = curr->children[pos];
            
            c++;
        }
        
        curr->isWord = true;
    }
    
    bool search(string word) {
        int c = 0;
        struct TRIE* curr = &root;
        int pos;
        while(word[c] != '\0')
        {
            pos = word[c] - 'a';
            
            if(curr->children[pos] == 0)
            {
                return false;
            }
            
            curr = curr->children[pos];
            
            c++;
        }
        
        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        int c = 0;
        struct TRIE* curr = &root;
        int pos;
        while(prefix[c] != '\0')
        {
            pos = prefix[c] - 'a';
            
            if(curr->children[pos] == 0)
            {
                return false;
            }
            
            curr = curr->children[pos];
            
            c++;
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

