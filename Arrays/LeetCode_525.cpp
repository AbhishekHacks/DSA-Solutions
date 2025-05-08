/*Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

*/

//Time Complexity -- O(n)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>seen;
        seen[0]=-1;
        int prefix_sum=0;
        int maxlength=0;
        for(int i=0;i<n;i++){
            prefix_sum+=(nums[i]==0)?-1:1;
            if(seen.count(prefix_sum)){
                maxlength = max(maxlength,i-seen[prefix_sum]);
            }
            else{
                seen[prefix_sum]=i;
            }
        }
        return maxlength;
    }
};
