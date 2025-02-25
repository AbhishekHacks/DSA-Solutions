/*Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //Time Complexity -- O(n)
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i])){
                return true;
            }
            else{
                m[nums[i]]=1;
            }
        }
        return false;
    }
};
