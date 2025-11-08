/*You are given an integer array nums of size n. For each index i where 0 <= i < n, define a subarray nums[start ... i] where start = max(0, i - nums[i]).

Return the total sum of all elements from the subarray defined for each index in the array.*/

//Time Complexity -- O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        //optimised approach -- O(n)
        vector<int>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int start = max(0,i-nums[i]);
            if(start==0){
                ans+=prefix[i];
            }
            else{
                ans+=(prefix[i]-prefix[start-1]);
            }
        }
        return ans;
    }
};
