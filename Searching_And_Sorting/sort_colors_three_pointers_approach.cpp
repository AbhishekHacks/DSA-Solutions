/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.*/

//Three pointers approach , although I prefer the previous approach of counting 0 1 and 2 and than modifying the array :)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int j=0;
        int k=nums.size()-1;
        while(i<k){
            if(j<=k){
                if(nums[j]==2&&(nums[k]==0||nums[k]==1)){
                    nums[j]=nums[k];
                    nums[k]=2;
                    j++;
                    k--;
                }
                else if((nums[j]==0||nums[j]==1)&&nums[k]==2){
                    j++;
                    k--;
                }
                else if((nums[j]==0||nums[j]==1)&&(nums[k]==1||nums[k]==0)){
                    j++;
                }
                else if(nums[j]==2&&nums[k]==2){
                    k--;
                }
            }
            else{
                if(nums[i]==0&&nums[k]==1){
                    i++;
                    k--;
                }
                else if(nums[i]==0&&nums[k]==0){
                    i++;
                }
                else if(nums[i]==1&&nums[k]==1){
                    k--;
                }
                else if(nums[i]==1&&nums[k]==0){
                    nums[i]=0;
                    nums[k]=1;
                    i++;
                    k--;
                }
            }
        }
    }
};
