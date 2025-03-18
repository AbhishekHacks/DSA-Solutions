/*You are given an array nums consisting of positive integers.

We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.

Return the length of the longest nice subarray.

A subarray is a contiguous part of an array.

Note that subarrays of length 1 are always considered nice.

*/

//Time Complexity -- O(n)

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left=0;
        int count_bits=0;
        int max_length=1;
        for(int right=0;right<nums.size();right++){
            while((count_bits&nums[right])!=0){
                count_bits^=nums[left];
                left++;
            }
            count_bits|=nums[right];
            max_length=max(max_length,right-left+1);
        }
        return max_length;
    }
};
