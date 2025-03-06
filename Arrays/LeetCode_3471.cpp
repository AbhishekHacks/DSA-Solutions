/*You are given an integer array nums and an integer k.

An integer x is almost missing from nums if x appears in exactly one subarray of size k within nums.

Return the largest almost missing integer from nums. If no such integer exists, return -1.

A subarray is a contiguous sequence of elements within an array.*/

//Time Complexity -- O(n)

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        int maximum=-1;
        if(k>n){
            return maximum;
        }
        if(k==n){
            for(int i=0;i<n;i++){
                if(maximum<nums[i]){
                    maximum=nums[i];
                }
            }
            return maximum;
        }
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        if(k==1){
            for(auto i:m){
                if(i.second==1){
                    if(maximum<i.first){
                        maximum=i.first;
                    }
                }
            }
            return maximum;
        }
        int first=nums[0];
        int last=nums[n-1];
        if(m[first]>1&&m[last]==1){
            return last;
        }
        else if(m[first]==1&&m[last]>1){
            return first;
        }
        else if(m[first]==1&&m[last]==1){
            return max(first,last);
        }
        return maximum;
    }
};
