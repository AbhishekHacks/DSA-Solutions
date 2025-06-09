/*You are given a 0-indexed integer array nums of length n and an integer k. In an operation, you can choose an element and multiply it by 2.

Return the maximum possible value of nums[0] | nums[1] | ... | nums[n - 1] that can be obtained after applying the operation on nums at most k times.

Note that a | b denotes the bitwise or between two integers a and b.*/

//Time Complexity -- O(n)

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1){
            return nums[0]<<k;
        }
        vector<long long>prefix(n,0);
        vector<long long>suffix(n,0);
        for(int i=0;i<n;i++){
            if(i==0){
                prefix[i]=nums[i];
            }
            else{
                prefix[i]=prefix[i-1]|nums[i];
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                suffix[i]=nums[i];
            }
            else{
                suffix[i]=suffix[i+1]|nums[i];
            }
        }
        long long maximum = 0;
        for(int i=0;i<n;i++){
            long long bitwise;
            if(i==0){
                bitwise = suffix[1]|((long long)nums[0]<<k);
            }
            else if(i==n-1){
                bitwise = prefix[n-2]|((long long)nums[n-1]<<k);
            }
            else{
                bitwise = prefix[i-1]|suffix[i+1]|((long long)nums[i]<<k);
            }
            if(maximum<bitwise){
                maximum=bitwise;
            }
        }
        return maximum;
    }
};
