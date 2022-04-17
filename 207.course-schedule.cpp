/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start


#define DEBUG   0

#if(DEBUG)
#include<iostream>
#include<vector>

using namespace std;
#endif

#define MAX_COURSE  100005   // 10^5


vector<int> adjlist[MAX_COURSE];
bool visited[MAX_COURSE];

void adjlist_init(int numCourses)
{
    for(int i = 0; i < numCourses; i++)
    {
        adjlist[i].clear();
    }
}

void visited_init(int numCourses)
{
    for(int i = 0; i < numCourses; i++)
    {
        visited[i] = false;
    }
}

// to come out of dfs recursion when cycle is present
bool bStop = false;

void doDFS(int course)
{
    if(bStop) return;
    
    // first mark this course as visited
    visited[course] = true;

    int listSize = adjlist[course].size();

    for(int i = 0; i < listSize; i++)
    {
        if(bStop) break;

        // if not visited visit the node
        if(!visited[adjlist[course][i]])
        {
            doDFS(adjlist[course][i]);

            // unvisit the node again to detect cycle properly?
            //visited[adjlist[course][i]] = false;
        }
        else // already visited means cycle is there.. so return 
        {
            bStop = true;
        }
    }
    
    // unvisit the node again to detect cycle properly?
    visited[course] = false;

    //[BUG FIX] for timeout issue
    // after checking one course for detecting cycle clear the edges to avoid rechecking
    // the path..
    // instead of deleting the path, can also make two visited variables like todo and done
    // done[i] means no nore dfs on that.. 
    // todo[i] means path cycle- do and undo
    adjlist[course].clear();

}
class Solution {
public:

    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        adjlist_init(numCourses);

        int len = prerequisites.size();
        int a,b;

        // make a directed graph using prerequisties vector 
        for(int i = 0; i < len; i++)
        {
            a = prerequisites[i][0];
            b = prerequisites[i][1];

            // form a directed edge from b --> a
            adjlist[b].push_back(a);

        }

        // find if the directed graph is cyclic or not
        // if cyclic , return false;
        int retval = true;
        bStop = false;
        
        //visited_init(numCourses);
        for(int i = 0; i < numCourses; i++)
        {
            visited_init(numCourses);
            
           // cout << "course number: " << i << endl;
            doDFS(i);
        }

        retval = !bStop; // if cycle is present (bstop TRUE), return false
        return retval;
        
    }
};


#if(DEBUG)
int main()
{
    /*
    5
    [[1,4],[2,4],[3,1],[3,2]]
    */
    class Solution* sol = new Solution();

    vector<vector<int>> prereq;

    vector<int> temp;
    temp.push_back(1);
    temp.push_back(4);
    prereq.push_back(temp);

    temp[0] = 2;
    temp[1] = 4;
    prereq.push_back(temp);

    temp[0] = 3;
    temp[1] = 1;
    prereq.push_back(temp);

    temp[0] = 3;
    temp[1] = 2;
    prereq.push_back(temp);

    
    sol->canFinish(5, prereq);
}
#endif
// @lc code=end

