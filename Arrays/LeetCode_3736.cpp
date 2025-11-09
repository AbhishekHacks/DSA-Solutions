/*You are given an integer array nums.

In one move, you may increase the value of any single element nums[i] by 1.

Return the minimum total number of moves required so that all elements in nums become equal.*/

//Time Complexity -- O(n)

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        auto largest_it = max_element(nums.begin(),nums.end());
        int largest = *largest_it;
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(largest-nums[i]);
        }
        return ans;
    }
};
