/*You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.*/

//Time Complexity -- O(n^2)

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int n =nums.size();

        int maximum = INT_MIN;
        for(int i=0;i<n;i++){
            maximum=max(maximum,nums[i]);
        }

        long long answer=0;

        for(int i=0;i<n;i++){
            int count=0;
            for(int j=i;j<n;j++){
                if(nums[j]==maximum){
                    count+=1;
                }
                if(count>=k){
                    answer+=1;
                }
            }
        }

        return answer;
    }
};
