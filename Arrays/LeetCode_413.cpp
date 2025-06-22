/*An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.*/

//Time Complexity -- O(n^2)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int answer=0;
        for(int i=0;i<n-1;i++){
            int diff = nums[i+1]-nums[i];
            int count=1;
            for(int j=i+1;j<n;j++){
                if(nums[j]-nums[j-1]==diff){
                    count+=1;
                    if(count>=3){
                        answer+=1;
                    }
                }
                else{
                    break;
                }
            }
        }
        return answer;
    }
};
