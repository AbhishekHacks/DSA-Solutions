/*You are given an integer array nums.

You must replace exactly one element in the array with any integer value in the range [-105, 105] (inclusive).

After performing this single replacement, determine the maximum possible product of any three elements at distinct indices from the modified array.

Return an integer denoting the maximum product achievable.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        long long product = 1;
        int count = 0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]!=0){
                product*=nums[i];
                count++;
                if(count==2){
                    break;
                }
            }
        }
        if(count!=2){
            return 0;
        }
        return product*100000;
    }
};
