/*Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.*/

//Time Complexity -- O(n)
//Space Complexity -- O(1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if((nums[i]!=(i+1))&&(nums[i]>0)&&(nums[i]<=n)){
                int temp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                while(temp>0&&temp<=n&&nums[temp-1]!=temp){
                    int index = nums[temp-1];
                    nums[temp-1]=temp;
                    temp = index;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=(i+1)){
                return i+1;
            }
        }
        return n+1;
    }
};
