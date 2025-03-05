/*Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.*/
//Brute Force approach--O(n2)

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        //Brute force 
        int max=INT_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                int xors = nums[i]^nums[j];
                if(max<xors){
                    max=xors;
                }
            }
        }
        return max;
    }
};
