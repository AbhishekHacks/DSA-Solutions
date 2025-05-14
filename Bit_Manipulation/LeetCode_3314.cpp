/*You are given an array nums consisting of n prime integers.

You need to construct an array ans of length n, such that, for each index i, the bitwise OR of ans[i] and ans[i] + 1 is equal to nums[i], i.e. ans[i] OR (ans[i] + 1) == nums[i].

Additionally, you must minimize each value of ans[i] in the resulting array.

If it is not possible to find such a value for ans[i] that satisfies the condition, then set ans[i] = -1.

 

*/

//Time Complexity -- O(N*M)

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>output(n,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i];j++){
                if((j|(j+1))==nums[i]){
                    output[i]=j;
                    break;
                }
            }
        }
        return output;
    }
};
