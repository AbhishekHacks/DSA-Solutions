/*Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.*/
//Time Complexity -- O(n^2)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //Brute Force approach
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(abs(i-j)>k){
                    break;
                }
                if(nums[i]==nums[j]){
                    return true;
                }
            }
        }
        return false;
    }
};
