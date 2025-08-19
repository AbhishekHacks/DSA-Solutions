/*Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.*/

//Time Complexity -- O(n)

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long count=0;
        long long total_subarrays = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
            }
            else{
                total_subarrays+=(count*(count+1))/2;
                count=0;
            }
        }
        total_subarrays+=(count*(count+1))/2;
        return total_subarrays;
    }
};
