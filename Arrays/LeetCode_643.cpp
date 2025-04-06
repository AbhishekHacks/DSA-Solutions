/*You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 */

//Time Complexity -- O(n)

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n=nums.size();
        
        double maximum = INT_MIN;

        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }

        double avg = sum/(double)k;
        if(maximum<avg){
            maximum=avg;
        }

        int startIndex=0;
        for(int i=k;i<n;i++){
            sum+=nums[i];
            sum-=nums[startIndex++];
            double avg = sum/(double)k;
            if(maximum<avg){
                maximum=avg;
            }
        }

        return maximum;
    }
};
