/*You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = n-1;
        int operations = 0;
        while(i<j){
            int sum = nums[i]+nums[j];
            if(sum==k){
                operations++;
                i++;
                j--;
            }
            else if(sum>k){
                j--;
            }
            else{
                i++;
            }
        }
        return operations;
    }
};
