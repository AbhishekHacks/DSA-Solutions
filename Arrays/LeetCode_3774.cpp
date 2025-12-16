/*You are given an integer array nums and an integer k.

Find the absolute difference between:

the sum of the k largest elements in the array; and
the sum of the k smallest elements in the array.
Return an integer denoting this difference.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=n-1,sum1=0,sum2=0;
        for(int i=0;i<k;i++){
            sum1+=nums[i];
            sum2+=nums[n-1-i];
        }
        return sum2-sum1;
    }
};
