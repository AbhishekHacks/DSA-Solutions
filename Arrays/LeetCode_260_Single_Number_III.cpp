/*Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.*/

//Time Complexity -- O(n)

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xors=0;
        for(int i=0;i<nums.size();i++){
            xors^=nums[i];
        }
        int set_bit=xors&(-xors);
        int num1=0;
        int num2=0;
        for(int i=0;i<nums.size();i++){
            if((nums[i]&set_bit)==0){
                num1^=nums[i];
            }
            else{
                num2^=nums[i];
            }
        }
        vector<int> v;
        v.push_back(num1);
        v.push_back(num2);
        return v;
    }
};
