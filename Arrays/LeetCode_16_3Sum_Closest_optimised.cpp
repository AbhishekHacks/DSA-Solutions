/*Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.*/

//Optimised to O(n2)


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //Optimise--O(n2)
        sort(nums.begin(),nums.end());
        int min=INT_MAX;
        int answer=0;
        for(int i=0;i<nums.size()-2;i++){
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                if(sum==target){
                    return sum;
                }
                else if(sum>target){
                    right--;
                }
                else{
                    left++;
                }
                if(min>abs(target-sum)){
                    min=abs(target-sum);
                    answer=sum;
                }
            }
        }
        return answer;
    }
};
