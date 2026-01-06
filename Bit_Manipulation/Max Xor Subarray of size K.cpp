/*Given an array of integers arr[]  and a number k. Return the maximum xor of a subarray of size k.

Note: A subarray is a contiguous part of any given array.*/

//Time Complexity -- O(n)

class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int temp_xor = 0;
        for(int i=0;i<k;i++){
            temp_xor^=arr[i];
        }
        int maximum_xor = temp_xor;
        int index = 0;
        for(int i=k;i<n;i++){
            temp_xor^=arr[i];
            temp_xor^=arr[index];
            maximum_xor=max(maximum_xor,temp_xor);
            index++;
        }
        return maximum_xor;
    }
};
