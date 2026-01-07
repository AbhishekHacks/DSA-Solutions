/*Given a 0-indexed integer array nums, return true if it can be made strictly increasing after removing exactly one element, or false otherwise. If the array is already strictly increasing, return true.

The array nums is strictly increasing if nums[i - 1] < nums[i] for each index (1 <= i < nums.length).*/

//Time Complexity -- O(n)

class Solution {
public:

    bool strictly_increasing(vector<int>&nums,int break_index){
        int n = nums.size();
        int i=0,j=1;
        bool strictly_increasing = true;
        while(j<n){
            if(i==break_index){
                i++;
                if(i==j){
                    j++;
                }
            }
            else if(j==break_index){
                j++;
            }
            if(j<n&&nums[i]>=nums[j]){
                strictly_increasing = false;
                break;
            }
            i++;
            j++;
        }
        if(strictly_increasing){
            return true;
        }
        return false;
    }

    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        int break_index1 = -1;
        int break_index2 = -1;
        for(int i=0;i<n-1;i++){
            if(nums[i]>=nums[i+1]){
                break_index1 = i;
                break_index2 = i+1;
                break;
            }
        }
        if(break_index1==-1){
            return true;
        }
        bool stric_inc1 = strictly_increasing(nums,break_index1);
        bool stric_inc2 = strictly_increasing(nums,break_index2);      
        if(stric_inc1||stric_inc2){
            return true;
        }
        return false;
    }
};
