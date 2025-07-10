/*You are given an integer eventTime denoting the duration of an event, where the event occurs from time t = 0 to time t = eventTime.

You are also given two integer arrays startTime and endTime, each of length n. These represent the start and end time of n non-overlapping meetings, where the ith meeting occurs during the time [startTime[i], endTime[i]].

You can reschedule at most k meetings by moving their start time while maintaining the same duration, to maximize the longest continuous period of free time during the event.

The relative order of all the meetings should stay the same and they should remain non-overlapping.

Return the maximum amount of free time possible after rearranging the meetings.

Note that the meetings can not be rescheduled to a time outside the event.

 */

//Time Complexity -- O(n)

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int>prefix;
        prefix.push_back(startTime[0]);
        for(int i=0;i<n-1;i++){
            int diff = startTime[i+1]-endTime[i];
            prefix.push_back(diff);
        }
        prefix.push_back(eventTime - endTime[n-1]);
        int sum = 0;
        for(int i=0;i<k+1;i++){
            sum+=prefix[i];
        }
        int longest = sum;
        int index = 0;
        for(int i=k+1;i<prefix.size();i++){
            sum+=prefix[i];
            sum-=prefix[index];
            longest = max(longest,sum);
            index++;
        }
        return longest;
    }
};
