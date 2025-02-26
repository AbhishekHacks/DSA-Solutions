/*Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.*/

//Brute force approach -- O(n3)

//This will get accepted successfully since the constraints are too small

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //Brute force--O(n3)
        int min=INT_MAX;
        int answer=0;
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    int sum = nums[i]+nums[j]+nums[k];
                    if(abs(sum-target)<min){
                        min=abs(sum-target);
                        answer=sum;
                    }
                }
            }
        }
        return answer;
    }
};
