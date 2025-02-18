/*You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.

The right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.

Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.*/

//Brute Force Approach 

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        //Brute force
        vector<int>answer;
        for(int i=0;i<intervals.size();i++){
            int minimum=INT_MAX;
            int index=-1;
            int end=intervals[i][1];
            for(int j=0;j<intervals.size();j++){
                if(intervals[j][0]>=end){
                    if(minimum>intervals[j][0]){
                        minimum=intervals[j][0];
                        index=j;
                    }
                }
            }
            answer.push_back(index);
        }
        return answer;
    }
};
