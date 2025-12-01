/*You are given an integer array nums of length n and an integer k.

An element in nums is said to be qualified if there exist at least k elements in the array that are strictly greater than it.

Return an integer denoting the total number of qualified elements in nums.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int count = 0;
        if(k==0){
            return n;
        }
        for(int i=0;i<n-k;i++){
            int index = upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();
            if(n-index>=k){
                count++;
            }
        }
        return count;
    }
};
