/*Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.

In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
Note that 0 is neither positive nor negative.*/

//O(log n)
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        if(nums[0]==0&&nums[nums.size()-1]==0){
            return 0;
        }
        int countpos=0;
        int countneg=0;
        if(nums[0]>0){
            return nums.size();
        }
        int start=0;
        int end=nums.size()-1;
        int index=-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]>0){
                end=mid-1;
                index=mid;
            }
            else{
                start=mid+1;
            }
        }
        int e;
        if(index==-1){
            countpos=0;
            e=nums.size()-1;
        }
        else{
            countpos=nums.size()-index;
            e=index-1;
        }
        if(nums[0]==0){
            countneg=0;
        }
        else{
            int s=0;
            int i=-1;
            while(s<=e){
                int mid=s+(e-s)/2;
                if(nums[mid]<0){
                    i=mid;
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
            countneg=i+1;
        }
        return max(countpos,countneg);
    }
};
