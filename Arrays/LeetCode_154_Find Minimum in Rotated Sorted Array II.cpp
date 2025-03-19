/*Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

You must decrease the overall operation steps as much as possible.*/

//Time Complexity -- O(n)

//This is the Brute Force approach

class Solution {
public:
    int findMin(vector<int>& nums) {
        //Brute Force -- O(n)
        int minimum = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(minimum>nums[i]){
                minimum=nums[i];
            }
        }
        return minimum;
    }
};
