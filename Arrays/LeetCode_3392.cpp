/*Given an integer array nums, return the number of subarrays of length 3 such that the sum of the first and third numbers equals exactly half of the second number.*/

//Time Complexity -- O(n)

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        int count=0;

        for(int i=0;i<n-2;i++){
            int sum = nums[i]+nums[i+2];
            if(nums[i+1]%2==0){
                if(sum==(nums[i+1]/2)){
                    count++;
                }
            }
        }

        return count;
    }
};
