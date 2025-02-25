/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.*/

//Time Complexity -- O(n^2) : optimal solution for 3Sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Step 1: Sort the array (O(n log n))
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++) {
            // Avoid duplicate values for nums[i]
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Move left pointer & skip duplicates
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Move right pointer & skip duplicates
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    // Move both pointers after finding a valid triplet
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++;  // Need a larger sum → move left forward
                } 
                else {
                    right--; // Need a smaller sum → move right backward
                }
            }
        }
        return result;
    }
};
