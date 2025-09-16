/*You are given a 2D integer array tasks where tasks[i] = [si, ti].

Each [si, ti] in tasks represents a task with start time si that takes ti units of time to finish.

Return the earliest time at which at least one task is finished.*/

//Time Complexity -- O(n)

class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int minimum = INT_MAX;
        int n = tasks.size();
        for(int i=0;i<n;i++){
            int sum = tasks[i][0]+tasks[i][1];
            minimum = min(minimum,sum);
        }
        return minimum;
    }
};
