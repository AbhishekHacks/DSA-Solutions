/*Given 'N' number of intervals, where each interval contains two integers denoting the boundaries of the interval. The task is to merge all the overlapping intervals and return the list of merged intervals sorted in ascending order.

Two intervals will be considered to be overlapping if the starting integer of one interval is less than or equal to the finishing integer of another interval, and greater than or equal to the starting integer of that interval.

Example:
for the given 5 intervals - [1,4], [3,5], [6,8], [10,12], [8,9].
Since intervals [1,4] and [3,5] overlap with each other, we will merge them into a single interval as [1,5].

Similarly [6,8] and [8,9] overlaps, we merge them into [6,9].

Interval [10,12] does not overlap with any interval.

Final List after merging overlapping intervals: [1,5], [6,9], [10,12]*/

#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> intervals)
{
    // Write your code here
    // Brute force
    vector<vector<int>> answer;
    sort(intervals.begin(),intervals.end(),[](const vector<int>&a , const vector<int>&b){
    return a[0]<b[0];
    });
    int flag=0;
    int i=0;
    int j=1;
    while(j<intervals.size()){
        vector<int> singleinterval;
        int opening=intervals[i][0];
        int closing=intervals[i][1];
        int nextopening=intervals[j][0];
        int nextclosing=intervals[j][1];
        if(nextopening>closing){
            singleinterval.push_back(opening);
            singleinterval.push_back(closing);
            answer.push_back(singleinterval);
            i=j;
            flag=1;
            singleinterval.erase(singleinterval.begin(),singleinterval.end());
        }
        else{
            if(closing>=nextclosing){
                singleinterval.push_back(opening);
                singleinterval.push_back(closing);
            }
            else{
                singleinterval.push_back(opening);
                singleinterval.push_back(nextclosing);
            }
            intervals[i]=singleinterval;
            flag=0;
        }
        j++;
        if(j==intervals.size()&&flag==1){
            singleinterval.push_back(intervals[i][0]);
            singleinterval.push_back(intervals[i][1]);
            answer.push_back(singleinterval);
        }
        else if(j==intervals.size()&&flag==0){
            answer.push_back(intervals[i]);
        }
    }
    if(answer.size()==0){
        answer.push_back(intervals[0]);
    }
    
    return answer;
}
