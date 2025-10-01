/*You are given an integer array nums.

Split the array into exactly two subarrays, left and right, such that left is strictly increasing and right is strictly decreasing.

Return the minimum possible absolute difference between the sums of left and right. If no valid split exists, return -1.*/

//Time Complexity -- O(n)

class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        if(n==2){
            return abs(nums[0]-nums[1]);
        }
        long long leftsum = 0;
        long long rightsum = 0;
        int index;
        for(int i=n-1;i>0;i--){
            rightsum+=nums[i];
            index=i;
            if(nums[i]>=nums[i-1]){
                break;
            }
        }
        for(int i=0;i<index-1;i++){
            if(nums[i]<nums[i+1]){
                leftsum+=nums[i];
            }
            else{
                return -1;
            }
        }
        leftsum+=nums[index-1];
        long long minimum = abs(leftsum-rightsum);
        if(nums[index-1]<nums[index]){
            leftsum+=nums[index];
            rightsum-=nums[index];
            minimum = min(minimum,abs(leftsum-rightsum));
        }
        return minimum;
    }
};
