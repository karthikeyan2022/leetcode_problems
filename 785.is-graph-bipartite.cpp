// [REF] : Graphs - Check whether a given graph is Bipartite using BFS
class Solution {
public:

    std::queue<int> bfsqueue;
    //std::vector<int> adjlist[101];
    int done[101] = {0, };
    int visited[101] = {0, };
    int color[101] = {-1, };
    bool bfs(int start, vector<vector<int>>& adjlist)
    {
        bfsqueue.push(start);
        visited[start] = true;
        color[start] = 0;

        int v;
        while(bfsqueue.empty() == false)
        {
            int u = bfsqueue.front();
            bfsqueue.pop();

            done[u] = true;

            for(int i = 0; i < adjlist[u].size(); i++)
            {
                v = adjlist[u][i];

                // process edge here
                if(done[v] == false)
                {
                    if(color[u] == color[v])
                    {
                        //cout << color[u] << " " << color[v] << endl;
                        return false;
                    }

                    color[v] = (color[u] + 1) % 2;
                }

                if(visited[v] == false)
                {
                    visited[v] = true;
                    bfsqueue.push(v);
                }
            }
        }

        return true;

    }
    bool isBipartite(vector<vector<int>>& adjlist) {
        
        int size = adjlist.size();

        for(int i = 0; i < 101; i++)
        {
            done[i] = visited[i]  = false;
            color[i] = -1;
        }

        int c = 0;
        for(int i = 0; i < size; i++)
        {
            if(visited[i] == false)
            {
                c++;
                if(bfs(i, adjlist) == false)
                    return false;
            }
        }

        return true;
    }
};
