/*Given an array nums of n integers and an integer k, determine whether there exist two adjacent subarrays of length k such that both subarrays are strictly increasing. Specifically, check if there are two subarrays starting at indices a and b (a < b), where:

Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly increasing.
The subarrays must be adjacent, meaning b = a + k.
Return true if it is possible to find two such subarrays, and false otherwise.*/

//Time Complexity -- O(n^2)

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>vec;
        for(int i=0;i<=n-k;i++){
            bool isincreasing = true;
            for(int j=i;j<i+k-1;j++){
                if(nums[j]>=nums[j+1]){
                    isincreasing = false;
                    break;
                }
            }
            if(isincreasing){
                vec.push_back(i);
            }
        }
        int l = vec.size();
        for(int i=0;i<l-1;i++){
            for(int j=i+1;j<l;j++){
                if(vec[j]-vec[i]==k){
                    return true;
                }
            }
        }
        return false;
    }
};
