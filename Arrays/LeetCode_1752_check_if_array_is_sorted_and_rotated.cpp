/*Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int pairs=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                pairs++;
            }
        }
        if(nums[nums.size()-1]>nums[0]){
            pairs++;
        }
        if(pairs>1){
            return 0;
        }
        return 1;
    }
};
