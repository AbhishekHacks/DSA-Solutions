/*You are given an array of integers nums. You are also given an integer original which is the first number that needs to be searched for in nums.

You then do the following steps:

If original is found in nums, multiply it by two (i.e., set original = 2 * original).
Otherwise, stop the process.
Repeat this process with the new number as long as you keep finding the number.
Return the final value of original.*/

//Time Complexity -- O(n2)

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bool process = true;
        while(process){
            int previous=original;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==original){
                    original=original*2;
                }
            }
            if(previous==original){
                process=false;
            }
        }
        return original;
    }
};
