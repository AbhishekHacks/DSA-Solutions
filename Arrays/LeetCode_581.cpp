/*Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.

Return the shortest such subarray and output its length.*/

//Time Complexity -- O(n)

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        unordered_map<int,int>m;
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            minimum = min(minimum,nums[i]);
            maximum = max(maximum,nums[i]);
        }
        for(int i=minimum;i<=maximum;i++){
            if(m.count(i)){
                for(int j=1;j<=m[i];j++){
                    temp.push_back(i);
                }
            }
        }
        int start = -1;
        int end = n-1;
        for(int i=0;i<n;i++){
            if(start==-1&&nums[i]!=temp[i]){
                start=i;
            }
            else if(nums[i]!=temp[i]){
                end=i;
            }
        }
        if(start==-1){
            return 0;
        }
        return end-start+1;
    }
};
