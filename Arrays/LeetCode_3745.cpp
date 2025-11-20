/*You are given an integer array nums.

Choose three elements a, b, and c from nums at distinct indices such that the value of the expression a + b - c is maximized.

Return an integer denoting the maximum possible value of this expression.

 */

//Time Complexity -- O(n)

class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int n=nums.size();
        int maximum1=INT_MIN,maximum2=INT_MIN;
        int minimum=INT_MAX;
        for(int i=0;i<n;i++){
            if(maximum1<=nums[i]){
                maximum2=maximum1;
                maximum1=nums[i];
            }
            else if(maximum2<=nums[i]){
                maximum2=nums[i];
            }
            minimum=min(minimum,nums[i]);
        }
        return maximum1+maximum2-minimum;
    }
};
