/*You are given an integer array nums and an integer target.

Return the number of subarrays of nums in which target is the majority element.

The majority element of a subarray is the element that appears strictly more than half of the times in that subarray.*/

//Time Complexity -- O(n^2)

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int answer = 0;
        for(int i=0;i<n;i++){
            int count_target = 0;
            for(int j=i;j<n;j++){
                if(nums[j]==target){
                    count_target++;
                }
                if(count_target>((j-i+1)/2)){
                    answer++;
                }
            }
        }
        return answer;
    }
};
