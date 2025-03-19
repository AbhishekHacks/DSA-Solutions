/*You are given a binary array nums.

You can do the following operation on the array any number of times (possibly zero):

Choose any 3 consecutive elements from the array and flip all of them.
Flipping an element means changing its value from 0 to 1, and from 1 to 0.

Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.*/

//Time Complexity -- O(n)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==0){
                nums[i]=1;
                if(nums[i+1]==1){
                    nums[i+1]=0;
                }
                else{
                    nums[i+1]=1;
                }
                if(nums[i+2]==0){
                    nums[i+2]=1;
                }
                else{
                    nums[i+2]=0;
                }
                count++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                return -1;
            }
        }
        return count;
    }
};
