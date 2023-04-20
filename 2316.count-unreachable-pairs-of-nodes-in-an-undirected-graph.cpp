/*
 * @lc app=leetcode id=2316 lang=cpp
 *
 * [2316] Count Unreachable Pairs of Nodes in an Undirected Graph
 */

// @lc code=start

#define DEBUG 1

#if(DEBUG)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#endif

class Solution {
public:

    int compcnt;

    int dfs(int u, vector<bool>& visited, vector<vector<int>>& adjlist)
    {
        int count = 0;
        int v;
        if(visited[u])
            return 0;

        visited[u] = true;
        count++;

        for(int i = 0; i < adjlist[u].size(); i++)
        {
            v = adjlist[u][i];

            if(!visited[v]) {
                count += dfs(v, visited, adjlist);
            }
        }

        return count;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {

        long long retVal = 0;
        vector<long long> component;
        vector<vector<int>> adjlist(n+1);
        compcnt = 0;
        int count = 0;

        vector<bool> visited(n, 0);

        if(edges.size() == 0)
        {
            return ((n * (n-1))/2);
        }

        int u, v;
        for(int i = 0; i < edges.size(); i++) {
            u = edges[i][0];
            v = edges[i][1];

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

        for(int i = 0; i < n; i++)
        {
            if(!visited[i]) {
                cout << "not vis: " << i << endl;
                count = dfs(i, visited, adjlist);
               // component[compcnt] = count;
                //compcnt++;
                component.push_back(count);
            }
        }

        sort(component.begin(), component.end());

        for(int i = 0; i < component.size(); i++) {
            cout << i << " " << component[i] << endl;
        }
        cout << endl;

        compcnt = component.size();      

        
        if(compcnt == 1)
            return 0;

        for(int i = 0; i < compcnt; i++)
        {
            for(int j = i+1; j < compcnt; j++) {
                retVal += (component[i]*component[j]);
            }
        }    

        return retVal;
    }
};

#if(DEBUG)
int main()
{
    class Solution* sol = new Solution();

    vector<vector<int>> edges;

    int count = sol->countPairs(100000, edges);

    cout << count << endl;
}
#endif
// @lc code=end

