/*You are given an integer array nums of size n.

Consider a non-empty subarray from nums that has the maximum possible bitwise AND.

In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.
Return the length of the longest such subarray.

The bitwise AND of an array is the bitwise AND of all the numbers in it.

A subarray is a contiguous sequence of elements within an array.*/

//Time Complexity -- O(N)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maximum = INT_MIN;
        for(int i=0;i<n;i++){
            maximum = max(maximum,nums[i]);
        }
        int count = 0;
        int maximum_len = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]==maximum){
                count+=1;
            }
            else{
                maximum_len = max(maximum_len,count);
                count=0;
            }
        }
        return max(maximum_len,count);
    }
};
