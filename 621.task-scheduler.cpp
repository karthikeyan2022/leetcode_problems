/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start

//not a optimized solution. but accepted using heap
struct node
{
    char ch;
    int lasttime;
    int hist;
};



struct compare
{
    // return true if count of node1 is less than node2's count 
    // node of larger count comes 'last' meaning front of the queue
    bool operator() (node* const& node1, node* const& node2)
    {
        if(node1->lasttime < node2->lasttime)
            return false;

        return true;
    }
};

class Solution {
public:

    priority_queue <node*, vector<node*>, compare> nodeHeap;

    int leastInterval(vector<char>& tasks, int n) {

        int cputime = 0;

        vector<int> hist(26,0);
        for(int i = 0; i < tasks.size(); i++)
        {
            hist[tasks[i]-'A']++;
        }

        for(int i = 0; i < 26; i++)
        {
            struct node* nnode = new node();
            nnode->ch = 'A' + i;
            nnode->lasttime = 1;
            nnode->hist = hist[i];
            if(nnode->hist != 0)
                nodeHeap.push(nnode);
        }

        cputime = 1;

        struct node* popnode = 0;
        while(!nodeHeap.empty())
        {
            // get pop node from heap
            // heap maintained only for lasttime.. hist should be decided seperately

            //1.1 get pop node
            vector<node*> nodelist;
            while(!nodeHeap.empty() && nodeHeap.top()->lasttime <= cputime)
            {
                nodelist.push_back(nodeHeap.top());    
                nodeHeap.pop();
            }
            
            int maxhist = 0;
            struct node* maxnode = 0;
            for(auto nnode : nodelist) {
                 if(nnode->hist > maxhist) {
                   maxhist = nnode->hist;
                   maxnode = nnode;
                 }
            }

            for(auto nnode : nodelist) {
                if(nnode == maxnode)
                  continue;

                nodeHeap.push(nnode);
            }
            
            popnode = maxnode;

            // 1.2if could not find popnode, just get from top element. fast forward time case
            if(popnode == 0) {
                popnode = nodeHeap.top();
                nodeHeap.pop();
            }

            // 2. update hist and update cputime
            //cout << "cpu: " << cputime << " t: " << popnode->ch << " hist: " << popnode->hist << endl;
            popnode->hist--;

            cputime = max(cputime, popnode->lasttime);

            popnode->lasttime = cputime + n + 1;

            // 3. push the node aggain
            if(popnode->hist)
                nodeHeap.push(popnode);

            //4. increment cputime
            cputime++;
        }

        return cputime-1;
        
    }
};
// @lc code=end

