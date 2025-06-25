/*Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray). The subsequence must be strictly increasing.

A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].*/

//Time Complexity -- O(n)

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maximum = 1;
        int count=1;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>=1){
                count++;
                if(maximum<count){
                    maximum=count;
                }
            }
            else{
                count=1;
            }
        }
        return maximum;
    }
};
