/*Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.*/

//Time Complexity -- O(NlogN)

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n=nums.size();
        int median=0;

        //sort the array to calculate the median
        sort(nums.begin(),nums.end());

        //calculate the median for n=even
        if(n%2==0){
            median = (nums[n/2]+nums[(n/2)-1])/2;
        }

        //calculate the median for n=odd
        else{
            median = nums[n/2];
        }

        //calculate the sum of distances of elements to the median
        int ans = 0;
        for(int i:nums){
            ans+=abs(median-i);
        }

        //return the answer
        return ans;
    }
};
