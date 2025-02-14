/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.*/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count_0=0;
        int count_1=0;
        int count_2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count_0+=1;
            }
            else if(nums[i]==1){
                count_1+=1;
            }
            else{
                count_2+=1;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(count_0>0){
                nums[i]=0;
                count_0--;
            }
            else if(count_1>0){
                nums[i]=1;
                count_1--;
            }
            else{
                nums[i]=2;
            }
        }
    }
};
