/*You are given an integer array nums.

Start by selecting a starting position curr such that nums[curr] == 0, and choose a movement direction of either left or right.

After that, you repeat the following process:

If curr is out of the range [0, n - 1], this process ends.
If nums[curr] == 0, move in the current direction by incrementing curr if you are moving right, or decrementing curr if you are moving left.
Else if nums[curr] > 0:
Decrement nums[curr] by 1.
Reverse your movement direction (left becomes right and vice versa).
Take a step in your new direction.
A selection of the initial position curr and movement direction is considered valid if every element in nums becomes 0 by the end of the process.

Return the number of possible valid selections.*/

//Time Complexity -- O(n^2)

class Solution {
public:

    bool isPossible(vector<int>temp,int n,bool right,int index){        
        //process start
        while(index>=0&&index<=n-1){
            if(temp[index]==0){
                if(right){
                    index++;
                }
                else{
                    index--;
                }
            }
            else if(temp[index]>0){
                temp[index]-=1;
                if(right){
                    right = false;
                    index--;
                }
                else{
                    right = true;
                    index++;
                }
            }
        }
        //check if every element become 0
        bool iszero = true;
        for(int j=0;j<n;j++){
            if(temp[j]!=0){
                iszero = false;
                break;
            }
        }
        if(iszero){
            return true;
        }
        return false;
    }

    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(isPossible(nums,n,true,i)&&isPossible(nums,n,false,i)){
                    count+=2;
                }
                else if(isPossible(nums,n,true,i)||isPossible(nums,n,false,i)){
                    count++;
                }
            }
        }
        return count;
    }
};
