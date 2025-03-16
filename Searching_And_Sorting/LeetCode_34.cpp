/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

*/

//Time Complexity -- O(logn)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        //first occurence
        int start=0;
        int end=n-1;
        int first=-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]==target){
                first=mid;
                end=mid-1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        //last occurence
        start=0;
        end=n-1;
        int last=-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]==target){
                last=mid;
                start=mid+1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        vector<int>v;
        if(first==-1){
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        v.push_back(first);
        v.push_back(last);
        return v;
    }
};
