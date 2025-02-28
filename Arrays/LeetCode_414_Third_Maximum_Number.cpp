/*Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=1;
        int ans=0;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]!=nums[i+1]){
                count++;
                if(count==3){
                    ans=nums[i];
                    break;
                }
            }
        }
        if(count<=2){
            return nums[nums.size()-1];
        }
        return ans;
    }
};
