/*You are given a 0-indexed array ‘NUMS’ consisting of ‘N’ integers. Sort the array ‘NUMS’ in such a way that the first half of the array contains only odd numbers sorted in non-increasing order and the second half contains only even numbers sorted in non-decreasing order.

Example:
Input: ‘N’ = 4,  ‘NUMS’ = [2, 5, 3, 6] 

Output: [5, 3, 2, 6]*/

//Time Complexity -- O(nlogn)

#include <bits/stdc++.h> 
void sortOddEven(vector<int>& nums){
    // Write your code here

    int n=nums.size();

    //taking output vector
    vector<int>output;

    //sort the array
    sort(nums.begin(),nums.end());

    //first run the loop for odd numbers starting from last
    for(int i=n-1;i>=0;i--){
        if(nums[i]%2!=0){
            output.push_back(nums[i]);
        }
    }

    //now run the loop for even numbers starting from 0
    for(int i=0;i<n;i++){
        if(nums[i]%2==0){
            output.push_back(nums[i]);
        }
    }

    //copy the output vector to original vector
    for(int i=0;i<n;i++){
        nums[i]=output[i];
    }
}
