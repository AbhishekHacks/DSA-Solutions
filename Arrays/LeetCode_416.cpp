/*Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.*/

//Time Complexity -- O(n*target)

class Solution {
public:

    bool subsetsum(vector<int>& nums,int n,int target){
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Base case: sum=0 is always possible (empty subset)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (nums[i-1] > j) {
                    dp[i][j] = dp[i-1][j]; // Exclude nums[i-1]
                } 
                else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]]; // Include or Exclude
                }
            }
        }
        return dp[n][target];
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(),nums.end());

        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        if(sum%2!=0){
            return false;
        }

        int find = sum/2;

        bool result = subsetsum(nums,n,find);

        return result;
    }
};
