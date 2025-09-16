/*Given an array arr[], find the sum of all the subarrays of the given array.

Note: It is guaranteed that the total sum will fit within a 32-bit integer range.*/

//Time Complexity -- O(n)

class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=(arr[i]*(i+1)*(n-i));
        }
        return sum;
    }
};
