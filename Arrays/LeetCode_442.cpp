/*Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output*/

//Time Complexity -- O(n)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            int index = abs(nums[i])-1;
            int element = nums[index];
            if(element<0){
                v.push_back(abs(nums[i]));
            }
            else{
                nums[index]=-nums[index];
            }
        }
        return v;
    }
};
