/*
 * @lc app=leetcode id=269 lang=cpp
 *
 * [269] alien dictionary
 * Lint code link: https://www.lintcode.com/problem/892 
 */


class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */

    vector<int> adjlist[26];
    string findOrder(int numCourses, vector<int>& indegree, vector<int>& valid) {
        
       

        //vector<int> adjlist[numCourses];

        // formm edge b --> a
        // for(auto edge : prerequisites) {
        //     int a = edge[0];
        //     int b = edge[1];

        //     adjlist[b].push_back(a);
        //     indegree[a]++;
        // }

        queue<int> courseq;
        //vector<int> retVal;
        string retstr;
        string remstr;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0 && valid[i]) {

                if(adjlist[i].size() == 0)
                {
                    char c = i + 'a';
                    remstr += c;
                    continue;
                }

                courseq.push(i);
            }
        }

       // return retVal;
        while(!courseq.empty()) 
        {
            int u = courseq.front();
            int v;
          //  cout << u << " ";
          char c = u + 'a';
            cout << c << " ";
            retstr += c;
            //retVal.push_back(u);
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
        sort(remstr.begin(), remstr.end());
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
        
        //retstr.append(remstr);
        if(finalstr.size() != numCourses)
        {
            cout << finalstr << endl;
            cout << numCourses << endl;
            return "";
        }

        //reverse(retVal.begin(), retVal.end());
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
        valid[u] = valid[v] = 1;
        indegree[v]++;
    }
    
    string alienOrder(vector<string> &words) {
        // Write your code here

        int len = words.size();
        vector<int> indegree(26, 0);
        vector<int> valid(26,0);
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
            for(int j = 0; j < minlen; j++) {
                
                valid[w1[j]-'a'] = valid[w2[j]-'a'] = 1;
                // if(j != 0 && w1[j-1] == w2[j-1])
                // {
                //     u = w1[j-1]-'a';
                //     v = w1[j]-'a';
                //     cout << u+'a' << " " << v+'a' << endl;
                //     checkAndPush(u, v, valid, indegree);

                //     u = w2[j-1]-'a';
                //     v = w2[j]-'a';
                //     checkAndPush(u, v, valid, indegree);
                // }

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

        for(int i = 0; i < 26; i++) {
            if(valid[i] > 0) {
                numChar++;
            }
        }


        return findOrder(numChar, indegree, valid);

    }
};