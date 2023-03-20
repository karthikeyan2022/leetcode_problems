/*

Lintcode https://www.lintcode.com/problem/591/
*/



struct node
{
    int n;
    int master;
};

class ConnectingGraph3 {
public:

    // global variables
    struct node nodes[100001];
    int N;
    int gcount;
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
     ConnectingGraph3(int n) {
        // initialize your data structure here.
        N = n;
        gcount = N;
        for(int i = 1; i <= n; i++)
        {
            nodes[i].n = i;
            nodes[i].master = i;
        }
    }

    int getMaster(int i)
    {
        
        if(i == nodes[i].master)
            return i;

        nodes[i].master = getMaster(nodes[i].master);

        return nodes[i].master;
        //return getMaster(nodes[i].master);
    }
    void connect(int a, int b) {
        //cout << "connect: " << a << " " << b << endl;
        // write your code here
        int m1 = getMaster(a);
        int m2 = getMaster(b);
        
        if(m1 != m2)
            gcount--;
       // nodes[a].master = m1;

       // refresh the master for a, m1
        nodes[m1].master = m2;
        getMaster(a);
        getMaster(m1);

        
        //cout << "m1: " << m1 << endl;
    }

    /**
     * @return: An integer
     */
    int query() {
        //cout << "query" << endl;
        // write your code here
       /* vector<bool> group(N+1,0);

        //cout << "query2" << endl;
        int midx = -1;
        for(int i = 1; i <= N; i++)
        {
            //cout << i << endl;
            midx = getMaster(i);
           // cout << "i: " << i << " midx: " << midx << endl;
            group[midx] = 1;
        }
        int count = 0;
        for(int i = 1; i <= N; i++)
        {
            if(group[i])
                count++;
        }
        */
        return gcount;
    }
};