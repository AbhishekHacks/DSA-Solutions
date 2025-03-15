/*There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.

The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.

You are given an integer array nums representing how much money is stashed in each house. More formally, the ith house from the left has nums[i] dollars.

You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always possible to steal at least k houses.

Return the minimum capability of the robber out of all the possible ways to steal at least k houses.*/

//Time Complexity -- O(nlogn)

class Solution {
public:

    bool isPossible(vector<int>& nums, int k,int mid){
        int i=0;
        int count=0;
        while(i<nums.size()){
            if(nums[i]<=mid){
                count+=1;
                i+=2;
            }
            else{
                i++;
            }
        }
        if(count>=k){
            return true;
        }
        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        int max=INT_MIN;
        int min=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(max<nums[i]){
                max=nums[i];
            }
            if(min>nums[i]){
                min=nums[i];
            }
        }
        int start=min;
        int end=max;
        int ans=0;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(nums,k,mid)){
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
