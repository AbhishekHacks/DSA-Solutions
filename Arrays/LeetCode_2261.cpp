/*Given an integer array nums and two integers k and p, return the number of distinct subarrays, which have at most k elements that are divisible by p.

Two arrays nums1 and nums2 are said to be distinct if:

They are of different lengths, or
There exists at least one index i where nums1[i] != nums2[i].
A subarray is defined as a non-empty contiguous sequence of elements in an array.*/

//Time Complexity -- O(n^3logn)

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        map<vector<int>,int>m;
        for(int i=0;i<n;i++){
            vector<int>vec;
            int count=0;
            for(int j=i;j<n;j++){
                if(nums[j]%p==0){
                    count++;
                    if(count>k){
                        break;
                    }
                }
                vec.push_back(nums[j]);
                m[vec]++;
            }
        }
        return m.size();
    }
};
