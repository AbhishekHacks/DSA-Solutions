/*There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = pivot_index(nums);
        int start=0;
        int end=0;
        if(target>=nums[pivot] && target<=nums[nums.size()-1]){
            start=pivot;
            end=nums.size()-1;
        }
        else{
            start=0;
            end=pivot-1;
        }
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return -1;
    }
    int pivot_index(vector<int>& nums){
        int start=0;
        int end=nums.size()-1;
        while(start<end){
            int mid=start+(end-start)/2;
            if(nums[mid]>=nums[0]){
                start=mid+1;
            }
            else{
                end=mid;
            }
        }
        return start;
    }
};
