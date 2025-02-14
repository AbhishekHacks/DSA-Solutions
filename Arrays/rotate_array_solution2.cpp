/*Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.*/
// A solid approach to solve this question is provided below --> passes every test cases

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        swap(nums,0,nums.size()-k-1);
        swap(nums,nums.size()-k,nums.size()-1);
        swap(nums,0,nums.size()-1);
    }
    void swap(vector<int>& nums,int i,int j){
        while(i<j){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;
            j--;
        }
    }
};
