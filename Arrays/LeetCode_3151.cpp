/*An array is considered special if the parity of every pair of adjacent elements is different. In other words, one element in each pair must be even, and the other must be odd.

You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.*/

//Time Complexity -- O(n)

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]%2==0){
                if(nums[i]%2==0){
                    return false;
                }
            }
            else{
                if(nums[i]%2!=0){
                    return false;
                }
            }
        }
        return true;
    }
};
