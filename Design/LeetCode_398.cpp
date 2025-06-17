/*Given an integer array nums with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the array nums.
int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple valid i's, then each index should have an equal probability of returning.*/

//Time Complexity -- O(n^2)

class Solution {
public:
    vector<int>nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
        srand(time(0));
    }
    
    int pick(int target) {
        vector<int>index;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                index.push_back(i);
            }
        }
        int r = rand()%index.size();
        return index[r];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
