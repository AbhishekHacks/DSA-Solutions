/*Given an integer array nums, return the length of the longest strictly increasing subsequence.*/

//Time Complexity -- O(nlog(n))

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>vec;
        for(int i=0;i<n;i++){
            if(vec.size()==0){
                vec.push_back(nums[i]);
            }
            else{
                if(vec[vec.size()-1]<nums[i]){
                    vec.push_back(nums[i]);
                }
                else{
                    int index = lower_bound(vec.begin(),vec.end(),nums[i])-vec.begin();
                    vec[index]=nums[i];
                }
            }
        }
        return vec.size();
    }
};
