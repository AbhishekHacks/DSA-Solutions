/*Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.

Return the length of the shortest subarray to remove.

A subarray is a contiguous subsequence of the array.

*/

//Time Complexity -- O(n)

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        stack<int>s;
        int left = 0;
        while(left+1<n&&arr[left]<=arr[left+1]){
            left++;
        }
        if(left==n-1){
            return 0;
        }
        int right = n-1;
        while(right-1>=0&&arr[right-1]<=arr[right]){
            right--;
        }
        int minLen = min(n-left-1,right);
        int i=0;
        int j=right;
        while(i<=left && j<n){
            if(arr[i]<=arr[j]){
                minLen=min(minLen,j-i-1);
                i++;
            }
            else{
                j++;
            }
        }
        return minLen;
    }
};
