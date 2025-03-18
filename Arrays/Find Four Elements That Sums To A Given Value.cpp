/*You are given an array/list 'ARR' of ‘N’ integers and an integer value ‘TARGET’. You need to check whether there exist four numbers (ARR[i], ARR[j], ARR[k], ARR[l]) such that (0 <= i < j < k < l < N) and ARR[i] + ARR[j] + ARR[k] + ARR[l] = 'TARGET'.

Note:
1. All four numbers should exist at different indices in the given array.
2. The answer is case-sensitive.*/

//Time Complexity -- O(n^3)

#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            int left = j+1;
            int right = n-1;
            int key = target-(arr[i]+arr[j]);
            while(left<right){
                int sum = arr[left]+arr[right];
                if(sum==key){
                    return "Yes";
                }
                else if(sum<key){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
    }
    return "No";
}
