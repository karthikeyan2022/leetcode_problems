/*
 * @lc app=leetcode id=269 lang=cpp
 *
 * [269] alien dictionary
 * Lint code link: https://www.lintcode.com/problem/892 
 */

#define CHAR_RANGE  (26)
class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */

    vector<int> adjlist[CHAR_RANGE];

    string findOrder(int numChars, vector<int>& indegree, vector<int>& valid) {
        
        queue<int> courseq;

        // this string is formed from adj list 
        string retstr;

        // this string is formed from remaining chars not associated with adjlist
        string remstr;

        for(int i = 0; i < CHAR_RANGE; i++) {
            if(indegree[i] == 0 && valid[i]) {

                // if nothing in adjlist, then it is dangling char
                if(adjlist[i].size() == 0)
                {
                    char c = i + 'a';
                    remstr += c;
                    continue;
                }

                courseq.push(i);
            }
        }

        // remstr is constructed. Now lexicographicall sort int
        sort(remstr.begin(), remstr.end());

        // construct retstr here.
        while(!courseq.empty()) 
        {
            int u = courseq.front();
            int v;
             char c = u + 'a';
            //cout << c << " ";
            retstr += c;
            
            courseq.pop();

            // 1.) traverse and remove the edge i.e., degrement the indegree
            for(int i = 0; i < adjlist[u].size(); i++)
            {
                v = adjlist[u][i];

                if(indegree[v] > 0)
                    indegree[v]--;

                if(indegree[v] == 0) {
                    courseq.push(v);
                    indegree[v] = -1;
                }
            }
        }

        // using two pointer sort the two string and merge it to finalstr   
        string finalstr = "";
        int l, r;
        l = r = 0;
        while(retstr[l] != '\0' || remstr[r] != '\0')
        {
            if(retstr[l] == '\0')
            {
               finalstr += remstr[r++];
            }
            else if(remstr[r] == '\0')
            {
                finalstr += retstr[l++];
            }
            else
            {
                if(retstr[l] < remstr[r])
                {
                    finalstr += retstr[l++];
                }
                else
                {
                    finalstr += remstr[r++];
                }
            }
        }
        
        if(finalstr.size() != numChars)
        {
            //cout << finalstr << endl;
            //cout << numChars << endl;
            return "";
        }

        return finalstr;
    }

    void checkAndPush(int u, int v, vector<int>&valid, vector<int>& indegree)
    {
        // check if already pushed..
        for(int i = 0; i < adjlist[u].size(); i++)
        {
            if(adjlist[u][i] == v)
                return;
        }

        adjlist[u].push_back(v);
        //valid[u] = valid[v] = 1;
        indegree[v]++;
    }

    string alienOrder(vector<string> &words) {
        // Write your code here

        int len = words.size();
        vector<int> indegree(CHAR_RANGE, 0);
        vector<int> valid(CHAR_RANGE,0);
        for(int i = 0; i < len-1; i++)
        {
            string w1 = words[i];
            string w2 = words[i+1];

            int minlen = min(w1.size(), w2.size());

            // invalid case : example: wrt  & wr
            if(w1.substr(0,minlen) == w2.substr(0,minlen) && w1.size() > w2.size())
            {
                return "";
            }

            int u, v;
            for(int i = 0; i < w1.size(); i++)
            {
                valid[w1[i]-'a']= 1;
            }
            for(int i = 0; i < w2.size(); i++)
            {
                valid[w2[i]-'a']= 1;
            }

            // Important: find the differ point and form an edge
            for(int j = 0; j < minlen; j++) {
                
                if(w1[j] != w2[j])
                {
                    u = w1[j]-'a';
                    v = w2[j]-'a';

                    checkAndPush(u, v, valid, indegree);
                    break;
                }

            }
        }

        int numChar = 0;

        for(int i = 0; i < CHAR_RANGE; i++) {
            if(valid[i] > 0) {
                numChar++;
            }
        }

        return findOrder(numChar, indegree, valid);

    }
};