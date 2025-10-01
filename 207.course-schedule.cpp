/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
// [REF] : Graphs - Detect Cycle in a Directed Graph using DFS

#define DEBUG   0

#if (DEBUG)
#include<iostream>
#include<vector>

using namespace std;
#endif

#define MAX_COURSE  2001   // 10^5

class Solution {
private:
    bool bcanFinish = true;
    vector<int> adjlist[MAX_COURSE];
    vector<int> visited;
    vector<int> done;
    vector<int> parent;

public:

    void initialize(int numCourses)
    {
        bcanFinish = true;
        for(int i = 0; i < numCourses; i++)
        {
            adjlist[i].clear();
            visited.push_back(0);
            done.push_back(0);
            parent.push_back(-1);
        }
    }

    void dfs(int u)
    {
        if(bcanFinish == false)
            return;
    
        //cout << "visited : " << u << endl;
        visited[u] = true;

        int v;
        for(int i = 0; i < adjlist[u].size(); i++)
        {
            v = adjlist[u][i];

            if(visited[v] == false)
            {
                parent[v] = u;
                dfs(v);
            }
            else if(done[v] == false)
            {
                if(parent[v] != u)
                {
                    //cout << "parent of " << v << " is not " << u << endl;
                    bcanFinish = false;
                }
            }

            if(bcanFinish == false)
            {
                 return;
            }
        }

        done[u] = true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        initialize(numCourses);
        //cout << "visited : " << numCourses << endl;
        int len = prerequisites.size();
        if (len <= 1)
            return true;
        
        int a,b;

        // make a directed graph using prerequisties vector 
        for(int i = 0; i < len; i++)
        {
            a = prerequisites[i][0];
            b = prerequisites[i][1];

            // form a directed edge from b --> a
            adjlist[b].push_back(a);

        }

        for(int i = 0; i < numCourses; i++)
        {
            //vector<int> done(numCourses, 0);
           // // // // cout << "course number: " << i << endl;
           //cout << "visited o : " << i << endl;
            if(visited[i] == false)
            {
                dfs(i);
            }

            if(bcanFinish == false)
            {
                //cout << "cant finish 4" << endl;
                 break;
            }
               
        }

        return bcanFinish;       
    }
};


#if(DEBUG)
int main()
{
    class Solution* sol = new Solution();

    vector<vector<int>> prereq;

    vector<int> temp;
    temp.push_back(2);
    temp.push_back(1);
    prereq.push_back(temp);

    temp[0] = 6;
    temp[1] = 1;
    prereq.push_back(temp);

    temp[0] = 3;
    temp[1] = 2;
    prereq.push_back(temp);

    temp[0] = 4;
    temp[1] = 3;
    prereq.push_back(temp);

    temp[0] = 5;
    temp[1] = 4;
    prereq.push_back(temp);

    temp[0] = 2;
    temp[1] = 5;
    prereq.push_back(temp);

    
    sol->canFinish(7, prereq);
}
#endif
// @lc code=end

