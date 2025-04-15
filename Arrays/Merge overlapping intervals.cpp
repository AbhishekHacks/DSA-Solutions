/*Given 'N' number of intervals, where each interval contains two integers denoting the boundaries of the interval. The task is to merge all the overlapping intervals and return the list of merged intervals sorted in ascending order.

Two intervals will be considered to be overlapping if the starting integer of one interval is less than or equal to the finishing integer of another interval, and greater than or equal to the starting integer of that interval.

Example:
for the given 5 intervals - [1,4], [3,5], [6,8], [10,12], [8,9].
Since intervals [1,4] and [3,5] overlap with each other, we will merge them into a single interval as [1,5].

Similarly [6,8] and [8,9] overlaps, we merge them into [6,9].

Interval [10,12] does not overlap with any interval.

Final List after merging overlapping intervals: [1,5], [6,9], [10,12]*/

//Time Complexity -- O(nlogn)

#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> intervals)
{
    // Write your code here

    int  n = intervals.size();
    vector<vector<int>>output;

    sort(intervals.begin(),intervals.end(),[](const vector<int>&a , const vector<int>&b){
        return a[0]<b[0];
    });

    int opening1 = intervals[0][0];
    int closing1 = intervals[0][1];

    int i = 1;
    while(i<n){
        int opening2 = intervals[i][0];
        int closing2 = intervals[i][1];
        if(opening2<=closing1){
            if(closing2>closing1){
                closing1=closing2;
            }
        }
        else{
            vector<int>temp;
            temp.push_back(opening1);
            temp.push_back(closing1);
            output.push_back(temp);
            opening1=opening2;
            closing1=closing2;
        }
        i++;
    }

    vector<int>temp;
    temp.push_back(opening1);
    temp.push_back(closing1);
    output.push_back(temp);

    return output;
}
