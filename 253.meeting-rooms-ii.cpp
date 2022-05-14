/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
// solved from Lintcode website
//https://www.lintcode.com/problem/919/
//https://aaronice.gitbook.io/lintcode/sweep-line/meeting-rooms-ii#approach-1-priority-queues



// sort the intervals based on the start time
// if start times are equal sort by end time
bool _my_sort(const Interval &a,
              const Interval &b)
{
    if(a.start < b.start)
        return true;

    if(a.start == b.start && a.end < b.end)
        return true;

    return false;
}


struct compareFunc
{
    // the interval 2 should be greater than interval 1
    // heap with intervals having faster end times
    bool operator() (Interval const& int1, Interval const& int2)
    {
        // if interval 2 comes before interval 1
        if(int2.end < int1.end)
            return true;

        if(int2.end == int1.end && int2.start < int1.start)
            return true;

        return false;
    }  
};

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    priority_queue<Interval, vector<Interval>, compareFunc> intervalHeap;

    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here

        int length = intervals.size();

        if(length < 2) return length;

        sort(intervals.begin(), intervals.end(), _my_sort);
    
        intervalHeap.push(intervals[0]);
    
        for(int i = 1; i < length; i++)
        {
            // iterate over the next first meeetings

            // if the fast end meetings in heap ends, then 
            // current meeting can be used for that room. 
            // Pop the current one 
            if(intervals[i].start >= intervalHeap.top().end)
            {
                intervalHeap.pop();
            }

            intervalHeap.push(intervals[i]);
        }

        return intervalHeap.size();
    }
};