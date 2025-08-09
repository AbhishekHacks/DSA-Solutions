/*Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.

Return the shortest such subarray and output its length.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(nums);
        sort(temp.begin(),temp.end());
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
