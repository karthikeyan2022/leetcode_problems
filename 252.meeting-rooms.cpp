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

// solved from lint code
// https://www.lintcode.com/problem/920/ 

bool _my_sort(const Interval &a,
              const Interval &b)
{
    return (a.start < b.start);
}
    
class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool isOverlap(Interval a, Interval b)
    {
        // <= wont come according to the problem statement
        if(b.start < a.end && b.start >= a.start)
            return true;

        if(a.start < b.end && a.start >= b.start)
            return true;

        return false;
    }

    bool canAttendMeetings(vector<Interval> &intervals) {
        // Write your code here
        int length = intervals.size();

        sort(intervals.begin(), intervals.end(), _my_sort);

         for(int i = 0; i < length-1; i++)
        {
            if(intervals[i].end > intervals[i+1].start)
                return false;

            // another method. no need
            //  if(isOverlap(intervals[i], intervals[i+1]))
            //      return false;
            
        }

        return true;
    }

};