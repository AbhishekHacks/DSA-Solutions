/*You are given a 0-indexed integer array nums.

Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.

The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

*/

//Time Complexity -- O(N^3)

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        int n=nums.size();

        //maximum value triplet
        long long maximum = INT_MIN;
        
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    long long value = (long long)(nums[i]-nums[j])*nums[k];
                    if(maximum<value){
                        maximum=value;
                    }
                }
            }
        }

        //return the maximum and if it is a negative value return 0;
        if(maximum<=0){
            return 0;
        }
        return maximum;
    }
};
