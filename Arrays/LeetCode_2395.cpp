/*Given a 0-indexed integer array nums, determine whether there exist two subarrays of length 2 with equal sum. Note that the two subarrays must begin at different indices.

Return true if these subarrays exist, and false otherwise.

A subarray is a contiguous non-empty sequence of elements within an array.

 */

//Time Complexity -- O(n)

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long,int>m;
        long long sum = 0;
        for(int i=0;i<2;i++){
            sum+=nums[i];
        }
        m[sum]++;
        for(int i=2;i<n;i++){
            sum+=nums[i];
            sum-=nums[i-2];
            if(m.count(sum)){
                return true;
            }
            m[sum]++;
        }
        return false;
    }
};
