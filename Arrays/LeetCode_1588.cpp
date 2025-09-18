/*Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.

A subarray is a contiguous subsequence of the array.*/

//Time Complexity -- O(n^2)

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int k=1;k<=n;k+=2){
            int temp_sum = 0;
            for(int i=0;i<k;i++){
                temp_sum+=arr[i];
            }
            sum+=temp_sum;
            int index=0;
            for(int i=k;i<n;i++){
                temp_sum+=arr[i];
                temp_sum-=arr[index];
                sum+=temp_sum;
                index++;
            }
        }
        return sum;
    }
};
