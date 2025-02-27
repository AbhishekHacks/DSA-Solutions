/*Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?*/

//Time Complexity -- O(N*log(Max-Min))

class Solution {
public:
    
    bool isPossible(vector<int>& nums, int k,int mid){
        int count=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                count++;
            }
        }
        if(count>=(nums.size()-k)){
            return true;
        }
        return false;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int min=INT_MAX;
        int max=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(min>nums[i]){
                min=nums[i];
            }
            if(max<nums[i]){
                max=nums[i];
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
