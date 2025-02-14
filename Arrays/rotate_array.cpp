/*Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==1 || k==0){
            return;
        }
        int count=0;
        int flag=0;
        int i=0;
        int start = i;
        int temp=nums[0];
        while(count!=nums.size()){
            if(flag==1){
                i=(i+1)%nums.size();
                start=i;
                temp=nums[i%nums.size()];
                flag=0;
            }
            else{
                int curr = nums[(i+k)%nums.size()];
                nums[(i+k)%nums.size()]=temp;
                temp=curr;
                i=(i+k)%nums.size();
                if(i==start){
                    flag=1;
                }
                count+=1;
            }
        }
    }
};
