/*Given an array of positive integers nums, return the maximum possible sum of an strictly increasing subarray in nums.

A subarray is defined as a contiguous sequence of numbers in an array.*/

//Time Complexity -- O(n)

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int sum=nums[0],maximum=INT_MIN;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                sum+=nums[i+1];
            }
            else{
                maximum=max(maximum,sum);
                sum=nums[i+1];
            }
        }
        maximum=max(maximum,sum);
        return maximum;
    }
};
