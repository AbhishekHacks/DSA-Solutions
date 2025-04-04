/*Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.*/

//Time Complexity -- O(N^2)

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n=nums.size();
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            int pro = 1;
            for(int j=i;j<n;j++){
                pro*=nums[j];
                ans=max(ans,pro);
            }
        }
        
        return ans;
    }
};
