/*You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>temp(nums);
        sort(nums.begin(),nums.end());
        unordered_map<int,int>m;
        for(int i=n-1;i>=n-k;i--){
            m[nums[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(m.count(temp[i])){
                ans.push_back(temp[i]);
                m[temp[i]]--;
                if(m[temp[i]]==0){
                    m.erase(temp[i]);
                }
            }
        }
        return ans;
    }
};
