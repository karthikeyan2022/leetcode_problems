/*
 * @lc app=leetcode id=269 lang=cpp
 *
 * [269] alien dictionary
 * Lint code link: https://www.lintcode.com/problem/892 
 */


#include<list>
struct node
{
    char c;
    struct node* children[26];
    int count;
};



class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */

    struct node root;

    void init_trie()
    {
        root.count = 0;
        for(int i = 0; i < 26; i++) {
            root.children[i] = 0;
        }
    }

    struct node* get_new_node(char c)
    {
        struct node* new_node = new node();
        new_node->c = c;
        new_node->count = 0;
        for(int i = 0; i < 26; i++) {
            new_node->children[i] = 0;
        }
        return new_node;
    }

    void insert_to_trie(string str)
    {
        struct node* curr = &root;
        int strlen = str.size();

        for(int i = 0; i < strlen; i++)
        {
            char c = str[i];
            int j;
            for(j = 0; j < curr->count; j++) {
                if( curr->children[j]->c == c)
                    break;
            }

            if(j != curr->count && curr->children[j])
            {
                curr = curr->children[j];
            }
            else
            {
                curr->count++;
                curr->children[j] = get_new_node(c);
                curr = curr->children[j];
            }
        }
    }
    
    void add_to_graph(struct node* parent, int i, vector<vector<int>>& adjlist)
    {
        int u = parent->children[i]->c - 'a';
        int v = parent->children[i+1]->c -'a';

        for(int j : adjlist[u])
        {
            if(j == v) return;
        }

        adjlist[u].push_back(v);
        char c1 = u + 'a';
        char c2 = v + 'a';
        //cout << "push u: " << c1 << " --> v: " << c2 << endl; 
        //cout << "push " << u << " --> " << v << endl;

    }
    void print_trie(vector<vector<int>>& adjlist)
    {
        struct node* curr = &root;
        list<struct node*> ll;

        ll.push_back(&root);

        int count = curr->count;


        while(!ll.empty())
        {
            struct node* curr = ll.front();
            ll.pop_front();

            count = curr->count;
            /*
            for(int i = 0; i < count; i++) {
                cout << curr->children[i]->c << " ";
            }
            cout << endl;*/

            for(int i = 0; i < count-1; i++) {
                add_to_graph(curr, i, adjlist);
            }

            for(int i = 0; i < count; i++) {
                ll.push_back(curr->children[i]);
            }
        }        
    }

    bool checkcycle(vector<vector<int>>& adjlist, int u, int p, vector<bool>& visited)
    {
        visited[u] = true;

        int len = adjlist[u].size();

        int v;
        // go u --> v
        for(int i = 0; i < len; i++)
        {
            v = adjlist[u][i];
            // if v is parent of u, skip
            if(v == p)
                continue;

            if(!visited[v])
            {
                if(checkcycle(adjlist, v , u /*parent*/ , visited))
                    return true;
            }
            else
            {
                // cycle is detected.
                //cout << "cycle is detected: " << v << " " << u << endl;
                return true;
            }
        }

        return false;
    }


    string getfinalstring(vector<vector<int>>& adjlist)
    {
        string str = "";
        list<int> ll;
        int count;
        int u = root.children[0]->c - 'a';

        ll.push_back(u);

        while(!ll.empty())
        {
            int num = ll.front();
            ll.pop_front();

            char ch = num + 'a';
            str.push_back(ch);

            count = adjlist[num].size();
            for(int i = 0; i < count; i++) {
                ll.push_back(adjlist[num][i]);
            }
        }
        return str;        
    }

    string alienOrder(vector<string> &words) {
        // Write your code here
        string str;

        vector<vector<int>> adjlist(26);

        init_trie();

        for(string s : words)
        {
            insert_to_trie(s);
        }

        print_trie(adjlist);

        vector<bool> visited(26, 0);

        for(int i = 0; i < 26; i++)
        {
            for(auto j : visited)
                j = 0;
            // dfs for each vector
            //if(!visited[i])
            {
                // check for cycle and if true return false
                if(checkcycle(adjlist, i, -1, visited))
                {
                    return "";
                }
            }
            
        }

        str = getfinalstring(adjlist);

        cout << "test case done" << endl;
        
        return str;

    }
};