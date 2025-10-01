
#define MAX_COURSES 2001

#define DFS 0
#define BFS_INDEGREE 1

#define MODE 1
class Solution {

    vector<int> adjlist[MAX_COURSES];
    
    // BFS DS
    vector<int> indegree;

    // DFS DS
    vector<int> visited;
    vector<int> done;
    vector<int> parent;
    bool bcanFinish;
    void initialize(int numCourses)
    {
        for(int i = 0; i < numCourses; i++)
        {
            adjlist[i].clear();
            indegree.push_back(0);
            visited.push_back(0);
            done.push_back(0);
            parent.push_back(-1);
        }
        bcanFinish = true;
    }
public:
    // retVal vector is needed for filling courses (return)
    bool dfs(int u, vector<int>& retVal)
    {
        if(bcanFinish == false)
        {
            retVal.clear();
            return false;
        }
    
        //cout << "visited : " << u << endl;
        visited[u] = true;

        int v;
        for(int i = 0; i < adjlist[u].size(); i++)
        {
            v = adjlist[u][i];

            if(visited[v] == false)
            {
                parent[v] = u;
                dfs(v, retVal);
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
                retVal.clear();
                return false;
            }
        }

        retVal.push_back(u);
        done[u] = true;
        return true;       
    }

    vector<int> bfs_indegree(int numCourses)
    {
        vector<int> retVal;
        queue<int> courseq;
        int v;
        // push nodes where indegree is 0
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0) {
                courseq.push(i);
            }
        }

        while(!courseq.empty()) 
        {
            int u = courseq.front();
            courseq.pop();
           
            //  cout << u << " ";
            retVal.push_back(u);

            // 1.) traverse and remove the edge i.e., degrement the indegree
            for(int i = 0; i < adjlist[u].size(); i++)
            {
                v = adjlist[u][i];

                if(indegree[v] > 0)
                    indegree[v]--;

                if(indegree[v] == 0) {
                    courseq.push(v);
                    indegree[v] = -1; // making the node invalid
                }
            }
        }

        

        if(retVal.size() != numCourses)
        {
            vector<int> empty;
            return empty;
        }

        //reverse(retVal.begin(), retVal.end());
        return retVal;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        initialize(numCourses);
        // form edge b --> a
        for(auto edge : prerequisites) {
            int a = edge[0];
            int b = edge[1];

            adjlist[b].push_back(a);
            indegree[a]++;
        }

#if (MODE == DFS)
        vector<int> retVal;
        for(int i = 0; i < numCourses; i++)
        {
            if(visited[i] == false)
            {
                if(dfs(i, retVal) == false)
                {
                    return retVal;
                }
            }
             
        }
        reverse(retVal.begin(), retVal.end());
        return retVal;

#elif (MODE == BFS_INDEGREE)
        return bfs_indegree(numCourses);
#endif
    }
};