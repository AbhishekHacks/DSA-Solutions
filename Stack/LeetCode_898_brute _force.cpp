/*Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.

The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.

A subarray is a contiguous non-empty sequence of elements within an array.*/

//Time Complexity -- O(n^2)

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_map<int,int>m;
        int n = arr.size();
        for(int i=0;i<n;i++){
            int bitwise_or = 0;
            for(int j=i;j<n;j++){
                bitwise_or|=arr[j];
                m[bitwise_or]++;
            }
        }
        return m.size();
    }
};
