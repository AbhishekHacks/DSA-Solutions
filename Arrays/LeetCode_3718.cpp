/*Given an integer array nums and an integer k, return the smallest positive multiple of k that is missing from nums.

A multiple of k is any positive integer divisible by k.*/

//Time Complexity -- O(max(maximum,n))

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>m;
        int maximum = INT_MIN;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            maximum = max(maximum,nums[i]);
        }
        for(int i=1;i<=maximum+1;i++){
            if(!m.count((k*i))){
                return (k*i);
            }
        }
        return 0;
    }
};
