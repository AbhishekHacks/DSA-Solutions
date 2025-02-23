/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.*/

class Solution {
public:
    
    bool isPossible(vector<int>& nums,int mid){
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=mid){
                count++;
            }
        }
        if(count>mid){
            return 1;
        }
        return 0;
    }
    
    int findDuplicate(vector<int>& nums) {
        int start=1;
        int end=nums.size()-1;
        int ans=0;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(nums,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};
