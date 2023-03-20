/*
https://www.lintcode.com/problem/178/

*/

class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */

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
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here

        //adj list
        vector<vector<int>> adjlist(n);

        int len = edges.size();
        int u,v;
        for(int i = 0; i < len; i++) {

            u = edges[i][0];
            v = edges[i][1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

        int component = 0;

        vector<bool> visited(n, 0);

        for(int i = 0; i < n; i++)
        {
            // dfs for each vector
            if(!visited[i])
            {
                component++;

                // check for cycle and if true return false
                if(checkcycle(adjlist, i, -1, visited))
                {
                    return false;
                }
            }
            
        }

       // cout << "component: " << component << endl;
        if(component > 1)
            return false;

        return true;


    }
};