/*Given an integer array arr[] sorted in ascending order, along with three integers: A, B, and C. The task is to transform each element x in the array using the quadratic function A*(x2) + B*x + C. After applying this transformation to every element, return the modified array in sorted order.*/

//Time Complexity -- O(nlogn)

class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        int n = arr.size();
        for(int i=0;i<n;i++){
            arr[i] = (A*pow(arr[i],2))+(B*arr[i])+C;
        }
        sort(arr.begin(),arr.end());
        return arr;
    }
};
