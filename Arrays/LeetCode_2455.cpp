/*Given an integer array nums of positive integers, return the average value of all even integers that are divisible by 3.

Note that the average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.

 */

//Time Complexity -- O(n)

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%6==0){
                count++;
                sum+=nums[i];
            }
        }
        if(count==0){
            return 0;
        }
        return sum/count;
    }
};
