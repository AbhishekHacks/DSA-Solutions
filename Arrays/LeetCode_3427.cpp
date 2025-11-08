/*You are given an integer array nums of size n. For each index i where 0 <= i < n, define a subarray nums[start ... i] where start = max(0, i - nums[i]).

Return the total sum of all elements from the subarray defined for each index in the array.*/

//Time Complexity -- O(n^2)

class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        //brute force approach -- O(n^2)
        int ans = 0;
        for(int i=0;i<n;i++){
            int start = max(0,i-nums[i]);
            for(int j=start;j<=i;j++){
                ans+=nums[j];
            }
        }
        return ans;
    }
};
