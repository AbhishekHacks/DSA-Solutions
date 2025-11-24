/*You are given an integer array nums. In one operation, you can add or subtract 1 from any element of nums.

Return the minimum number of operations to make all elements of nums divisible by 3.*/

//Time Complexity -- O(n)

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]%3!=0){
                count+=1;
            }
        }
        return count;
    }
};
