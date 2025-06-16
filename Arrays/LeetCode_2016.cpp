/*Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

Return the maximum difference. If no such i and j exists, return -1.*/

//Time Complexity -- O(n)

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minimum = nums[0];
        int n = nums.size();
        int max_difference = -1;
        for(int i=1;i<n;i++){
            if(nums[i]>minimum){
                max_difference = max(max_difference,(nums[i]-minimum));
            }
            else{
                minimum = min(minimum,nums[i]);
            }
        }
        return max_difference;
    }
};
