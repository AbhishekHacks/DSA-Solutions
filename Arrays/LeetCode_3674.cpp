/*You are given an integer array nums of length n.

In one operation, choose any subarray nums[l...r] (0 <= l <= r < n) and replace each element in that subarray with the bitwise AND of all elements.

Return the minimum number of operations required to make all elements of nums equal.

A subarray is a contiguous non-empty sequence of elements within an array.*/

//Time Complexity -- O(n)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        auto it1 = max_element(nums.begin(),nums.end());
        auto it2 = min_element(nums.begin(),nums.end());
        if(*it1==*it2){
            return 0;
        }
        return 1;
    }
};
