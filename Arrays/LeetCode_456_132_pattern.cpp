/*Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.*/

//Brute force approach -- O(n3)

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //Brute Force approach -- O(n3)
        if(nums.size()<3){
            return 0;
        }
        else{
            for(int i=0;i<nums.size()-2;i++){
                for(int j=i+1;j<nums.size()-1;j++){
                    for(int k=j+1;k<nums.size();k++){
                        if(nums[i]<nums[k]&&nums[k]<nums[j]){
                            return 1;
                        }
                    }
                }
            }
            return 0;
        }
    }
};
