/*Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.*/

//Time Complexity -- O(n)

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2){
            return 0;
        }
        int min=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(min>nums[i]){
                min=nums[i];
            }
        }
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int len=INT_MIN;
        int prev=min;
        for(auto i:m){
            int diff=i.first-prev;
            if(len<diff){
                len=diff;
            }
            prev=i.first;
        }
        return len;
    }
};
