/*Given an integer array nums, design an algorithm to randomly shuffle the array. All permutations of the array should be equally likely as a result of the shuffling.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the integer array nums.
int[] reset() Resets the array to its original configuration and returns it.
int[] shuffle() Returns a random shuffling of the array.*/

//Time Complexity -- O(n)

class Solution {
public:
    vector<int>curr;
    vector<int>start;
    Solution(vector<int>& nums) {
        this->start = nums;
        this->curr = nums;
    }
    
    vector<int> reset() {
        return start;
    }
    
    vector<int> shuffle() {
        random_device rd;
        mt19937 g(rd()); 
        std::shuffle(curr.begin(),curr.end(),g);
        return curr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
