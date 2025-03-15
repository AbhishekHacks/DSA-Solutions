/*You are given an integer array nums where the largest integer is unique.

Determine whether the largest element in the array is at least twice as much as every other number in the array. If it is, return the index of the largest element, or return -1 otherwise.*/

//Time Complexity -- O(n)

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = INT_MIN;
        int index=-1;
        for(int i=0;i<nums.size();i++){
            if(largest<nums[i]){
                largest=nums[i];
                index=i;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(i!=index){
                if(largest<(2*nums[i])){
                    return -1;
                }
            }
        }
        return index;
    }
};
