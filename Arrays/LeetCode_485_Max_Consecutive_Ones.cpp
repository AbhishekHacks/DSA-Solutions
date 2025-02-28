/*Given a binary array nums, return the maximum number of consecutive 1's in the array.*/

//Time Complexity -- O(n)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int consecutive=0;
        int maxconsecutive=INT_MIN;
        int i=0;
        while(i<nums.size()){
            if(nums[i]==1){
                consecutive++;
            }
            else{
                if(maxconsecutive<consecutive){
                    maxconsecutive=consecutive;
                }
                consecutive=0;
            }
            i++;
        }
        if(maxconsecutive<consecutive){
            maxconsecutive=consecutive;
        }
        return maxconsecutive;
    }
};
