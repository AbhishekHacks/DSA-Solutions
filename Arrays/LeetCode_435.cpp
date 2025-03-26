/*Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

*/

//Time Complexity -- O(NlogN)

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        //lets sort the 2D vector first in order to align the intervals
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a, const vector<int>&b){
            return a[1]<b[1];
        });

        //take a count variable to measure the number of intervals removed
        int count=0;

        //take 4 pointers to check the over lapping of two intervals and remove them accordingly and mind that once an interval is removed we need to move the beginning pointers carefully
        int opening1=intervals[0][0];
        int closing1=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int opening2=intervals[i][0];
            int closing2=intervals[i][1];
            if(opening2<closing1){
                count++;
            }
            else{
                opening1=opening2;
                closing1=closing2;
            }
        }

        //finally return the count of removed intervals
        return count;
    }
};
