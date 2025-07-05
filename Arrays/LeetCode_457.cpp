/*You are playing a game involving a circular array of non-zero integers nums. Each nums[i] denotes the number of indices forward/backward you must move if you are located at index i:

If nums[i] is positive, move nums[i] steps forward, and
If nums[i] is negative, move nums[i] steps backward.
Since the array is circular, you may assume that moving forward from the last element puts you on the first element, and moving backwards from the first element puts you on the last element.

A cycle in the array consists of a sequence of indices seq of length k where:

Following the movement rules above results in the repeating index sequence seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...
Every nums[seq[j]] is either all positive or all negative.
k > 1
Return true if there is a cycle in nums, or false otherwise.*/

//Time Complexity -- O(n^2)

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            bool backward = false;
            bool forward = false;
            if(nums[i]>0){
                forward = true;
            }
            else{
                backward = true;
            }
            unordered_map<int,int>m;
            m[i]++;
            int index = i;
            for(int op = 1;op<=nums.size();op++){
                index=((index+nums[index])+nums.size())%nums.size();
                if(forward&&nums[index]<0){
                    break;
                }
                else if(backward&&nums[index]>0){
                    break;
                }
                if(index==i&&m.size()>1){
                    return true;
                }
                m[index]++;
            }
        }
        return false;
    }
};
