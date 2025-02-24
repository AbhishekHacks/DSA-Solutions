/*Given an array of integers nums and an integer k, an element nums[i] is considered good if it is strictly greater than the elements at indices i - k and i + k (if those indices exist). If neither of these indices exists, nums[i] is still considered good.

Return the sum of all the good elements in the array.*/

//Time Complexity -- O(n)

class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(i-k>=0&&i+k<=nums.size()-1){
                if(nums[i]>nums[i-k] && nums[i]>nums[i+k]){
                    sum+=nums[i];
                }
            }
            else if(i-k>=0){
                if(nums[i]>nums[i-k]){
                    sum+=nums[i];
                }
            }
            else if(i+k<=nums.size()-1){
                if(nums[i]>nums[i+k]){
                    sum+=nums[i];
                }
            }
            else{
                sum+=nums[i];
            }
        }
        return sum;
    }
};
