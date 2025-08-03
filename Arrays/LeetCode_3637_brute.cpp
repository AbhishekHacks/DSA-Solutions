/*You are given an integer array nums of length n.

An array is trionic if there exist indices 0 < p < q < n − 1 such that:

nums[0...p] is strictly increasing,
nums[p...q] is strictly decreasing,
nums[q...n − 1] is strictly increasing.
Return true if nums is trionic, otherwise return false.*/

//Time Complexity -- O(n^3)

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        for(int p=1;p<n-2;p++){
            for(int q=p+1;q<n-1;q++){
                bool first = true;
                bool second = true;
                bool third = true;
                //first
                for(int i=0;i<p;i++){
                    if(nums[i]>=nums[i+1]){
                        first = false;
                        break;
                    }
                }
                //second
                for(int i=p;i<q;i++){
                    if(nums[i]<=nums[i+1]){
                        second = false;
                        break;
                    }
                }
                //third
                for(int i=q;i<n-1;i++){
                    if(nums[i]>=nums[i+1]){
                        third = false;
                        break;
                    }
                }
                if(first&&second&&third){
                    return true;
                }
            }
        }
        return false;
    }
};
