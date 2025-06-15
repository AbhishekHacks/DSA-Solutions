/*You are given an integer array nums.

A special triplet is defined as a triplet of indices (i, j, k) such that:

0 <= i < j < k < n, where n = nums.length
nums[i] == nums[j] * 2
nums[k] == nums[j] * 2
Return the total number of special triplets in the array.

Since the answer may be large, return it modulo 109 + 7.*/

//Time Complexity -- O(n)

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        long long count=0;
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        for(int i=n-1;i>=1;i--){
            m2[nums[i]]++;
        }
        for(int i=1;i<n-1;i++){
            int element = nums[i]*2;
            m1[nums[i-1]]++;
            m2[nums[i]]--;
            if(m2[nums[i]]==0){
                m2.erase(nums[i]);
            }
            long long lefttotal=0;
            long long righttotal=0;
            if(m1.count(element)){
                lefttotal=m1[element];
            }
            if(m2.count(element)){
                righttotal=m2[element];
            }
            count+=(lefttotal*righttotal)%1000000007;
        }
        return count%1000000007;
    }
};
