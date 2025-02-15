/*Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=0;
        int i=0;
        int j=i+1;
        nums[index++]=nums[0];
        while(j<nums.size()){
            if(nums[i]!=nums[j]){
                nums[index++]=nums[j];
                i=j;
            }
            j++;
        }
        return index;
    }
};
