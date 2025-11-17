/*Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.*/

//Time Complexity -- O(n)

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        int prev=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                if(prev!=-1){
                    if(i-prev-1<k){
                        return false;
                    }
                }
                prev=i;
            }
        }
        return true;
    }
};
