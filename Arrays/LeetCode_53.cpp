/*Given an integer array nums, find the subarray with the largest sum, and return its sum.*/

//Time Complexity -- O(N)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        //using kadane's algorithm
        int n = nums.size();

        //declaring current sum and maximum sum
        int curr_sum=0;
        int max_sum=INT_MIN;

        //adding elements sum to current and maximum in max_sum
        for(int i=0;i<n;i++){
            curr_sum+=nums[i];
            max_sum=max(max_sum,curr_sum);
            if(curr_sum<0){
                curr_sum=0; // if current sum is negative make it zero
            }
        }

        //return the maximum sum
        return max_sum;
    }
};
