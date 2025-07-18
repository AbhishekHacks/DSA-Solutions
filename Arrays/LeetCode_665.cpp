/*Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).*/

//Time Complexity -- O(n)

class Solution {
public:

    bool checkarray(vector<int>temp,int n){
        for(int i=0;i<n-1;i++){
            if(temp[i]>temp[i+1]){
                return false;
            }
        }
        return true;
    }
    
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(nums);
        if(checkarray(temp,n)){
            return true;
        }
        for(int i=0;i<n-1;i++){
            if(temp[i]>temp[i+1]){
                temp[i+1]=temp[i];
                break;
            }
        }
        if(checkarray(temp,n)){
            return true;
        }
        temp = nums;
        for(int i=0;i<n-1;i++){
            if(temp[i]>temp[i+1]){
                if(i==0){
                    temp[i]=temp[i+1];
                }
                else{
                    temp[i]=temp[i-1];
                }
                break;
            }
        }
        if(checkarray(temp,n)){
            return true;
        }
        return false;
    }
};
