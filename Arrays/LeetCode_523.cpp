/*Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
*/

//Time Complexity -- O(N)

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        if (n < 2) {
            return false;
        }

        // Check for two consecutive zeros
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == 0 && nums[i + 1] == 0) {
                return true;
            }
        }

        // If k is zero, the only possibility is two consecutive zeros
        if (k == 0) {
            return false;
        }

        unordered_map<int, int> remainder_map;
        remainder_map[0] = -1; // Initialize to handle subarrays starting from index 0
        int running_sum = 0;

        for (int i = 0; i < n; i++) {
            running_sum += nums[i];
            int remainder = running_sum % k;

            // Adjust for negative remainders
            if (remainder < 0) {
                remainder += k;
            }

            if (remainder_map.find(remainder) != remainder_map.end()) {
                if (i - remainder_map[remainder] > 1) {
                    return true;
                }
            } else {
                remainder_map[remainder] = i;
            }
        }

        return false;
    }
};
