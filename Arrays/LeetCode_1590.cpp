/*Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.*/

//Time Complexity -- O(n)

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int currentSum = 0;
        unordered_map<int,int>m={{0,-1}};
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = (sum+nums[i])%p;
        }
        int target = sum%p;
        if(target==0){
            return 0;
        }
        int minLen = n;
        for(int i=0;i<n;i++){
            currentSum = (currentSum+nums[i])%p;
            int needed = (currentSum-target+p)%p;
            if(m.count(needed)){
                minLen=min(minLen,(i-m[needed]));
            }
            m[currentSum]=i;
        }
        if(minLen==n){
            return -1;
        }
        return minLen;
    }
};
