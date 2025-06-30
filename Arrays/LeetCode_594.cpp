/*We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.*/

//Time Complexity -- O(n)

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int longest = 0;
        for(int i=0;i<n;i++){
            int count1 = m[nums[i]];
            int count2 = m[nums[i]+1];
            if(count2!=0){
                int sum = count1+count2;
                longest = max(longest,sum);
            }
        }
        return longest;
    }
};
