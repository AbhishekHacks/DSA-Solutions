/*Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.*/

//Time Complexity -- O(n)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>zeros;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeros.push_back(i);
            }
        }
        int len = zeros.size();
        if(k>=len){
            return n;
        }
        int maximum = INT_MIN;
        for(int i=0;i+k-1<len;i++){
            if(i==0){
                maximum = max(maximum,zeros[i+k]);
            }
            else if(i==len-k){
                maximum = max(maximum,n-1-zeros[i-1]);
            }
            else{
                maximum = max(maximum,zeros[i+k]-zeros[i-1]-1);
            }
        }
        return maximum;
    }
};
