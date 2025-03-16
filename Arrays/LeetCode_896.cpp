/*An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.*/

//Time Complexity -- O(n)

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing =false;
        bool decreasing =false;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                if(!decreasing){
                    increasing = true;
                }
                else{
                    return false;
                }
            }
            else if(nums[i]>nums[i+1]){
                if(!increasing){
                    decreasing=true;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
