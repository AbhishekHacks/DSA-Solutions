/*Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.*/

//Time Complexity -- O(NlogN)

class Solution {
public:

    //function to check if mid can be the possible length subarray
    bool isPossible(int target, vector<int>& nums,int mid){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(i>=mid-1){
                if(sum>=target){
                    return true;
                }
                sum-=nums[i-(mid-1)];
            }
        }
        return false;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        
        //applying binary search to find the minimum length of the subarray
        int start=1;
        int end=nums.size();
        int ans=0;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(target,nums,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }

        //return the minimal subarray length
        return ans;
    }
};
