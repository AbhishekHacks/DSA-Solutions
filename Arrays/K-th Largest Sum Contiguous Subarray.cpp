/*Given an array arr[] of size n, find the sum of the K-th largest sum among all contiguous subarrays. In other words, identify the K-th largest sum from all possible subarrays and return it.*/

//Time Complexity -- O(n^2log(n^2))

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        vector<int>sumofsubarrays;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                sumofsubarrays.push_back(sum);
            }
        }
        sort(sumofsubarrays.begin(),sumofsubarrays.end());
        int size = sumofsubarrays.size();
        return sumofsubarrays[size-k];
    }
};
