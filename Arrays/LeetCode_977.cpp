/*Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.*/

//Time Complexity -- O(n)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        int i=0,j=n-1;
        int index=n-1;
        while(i<=j){
            if(abs(nums[i])<abs(nums[j])){
                ans[index--]=pow(nums[j],2);
                j--;
            }
            else if(abs(nums[i])>abs(nums[j])){
                ans[index--]=pow(nums[i],2);
                i++;
            }
            else{
                ans[index--]=pow(nums[i],2);
                if(index==-1){
                    break;
                }
                ans[index--]=pow(nums[j],2);
                i++;
                j--;
            }
        }
        return ans;
    }
};
