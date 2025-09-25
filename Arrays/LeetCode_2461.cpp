/*You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.*/

//Time Complexity -- O(n)

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        long long sum=0;
        for(int i=0;i<k;i++){
            m[nums[i]]++;
            sum+=nums[i];
        }
        long long maximum=0;
        if(m.size()==k){
            maximum=sum;
        }
        int index=0;
        for(int i=k;i<n;i++){
            sum+=nums[i];
            m[nums[i]]++;
            sum-=nums[index];
            m[nums[index]]--;
            if(m[nums[index]]==0){
                m.erase(nums[index]);
            }
            if(m.size()==k){
                maximum=max(maximum,sum);
            }
            index++;
        }
        return maximum;
    }
};
