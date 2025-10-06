/*You are given an integer array nums.

Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.*/

//Time Complexity -- O(n)

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int bitwise_xor = 0;
        int maximum = INT_MIN;
        for(int i=0;i<n;i++){
            bitwise_xor^=nums[i];
            maximum = max(maximum,nums[i]);
        }
        if(bitwise_xor!=0){
            return n;
        }
        else if(maximum==0){
            return 0;
        }
        return n-1;
    }
};
