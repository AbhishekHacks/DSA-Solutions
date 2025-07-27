/*You are given a 0-indexed integer array nums. An index i is part of a hill in nums if the closest non-equal neighbors of i are smaller than nums[i]. Similarly, an index i is part of a valley in nums if the closest non-equal neighbors of i are larger than nums[i]. Adjacent indices i and j are part of the same hill or valley if nums[i] == nums[j].

Note that for an index to be part of a hill or valley, it must have a non-equal neighbor on both the left and right of the index.

Return the number of hills and valleys in nums.*/

//Time Complexity -- O(n^2)

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int i = 1;
        while(i<n-1){
            if(nums[i]!=nums[i-1]){
                int ptr1 = i-1;
                int ptr2 = i+1;
                while(ptr1>=0){
                    if(nums[ptr1]!=nums[i]){
                        break;
                    }
                    ptr1--;
                }
                while(ptr2<n){
                    if(nums[ptr2]!=nums[i]){
                        break;
                    }
                    ptr2++;
                }
                if((ptr1>=0)&&(ptr2<n)&&((nums[i]>nums[ptr1]&&nums[i]>nums[ptr2])||(nums[i]<nums[ptr1]&&nums[i]<nums[ptr2]))){
                    count++;
                }
            }
            i++;
        }
        return count;
    }
};
