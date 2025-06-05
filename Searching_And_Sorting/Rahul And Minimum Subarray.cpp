/*Rahul is a programming enthusiast. He is currently learning about arrays/lists. One day his teacher asked him to solve a very difficult problem. The problem was to find the length of the smallest subarray(subarray is a contiguous part of an array/list) in a given array/list ‘ARR’ of size ‘N’ with its sum greater than a given value. If there is no such subarray return 0.

Example: Given an ‘ARR’: [1, 2, 21, 7, 6, 12] and a number ‘X’: 23. The length of the smallest subarray is 2 as the subarray is [21, 7].

Note: Here are multiple subarrays whose sum is greater than ‘X’ such as [1, 2, 21] or [7, 6, 12] but we have to choose the minimum length subarray.*/

//Time Complexity -- O(nlogn)

#include <bits/stdc++.h> 

bool isPossible(vector<int>& arr, int n, int target, int mid){
    int sum=0;
    for(int i=0;i<mid;i++){
        sum+=arr[i];
    }
    if(sum>target){
        return true;
    }
    int index=0;
    for(int i=mid;i<n;i++){
        sum+=arr[i];
        sum-=arr[index];
        if(sum>target){
            return true;
        }
        index++;
    }
    return false;
}

int minSubArrayLen(vector<int>& arr, int target, int n) {
    // Write your code here.
    int start=1;
    int end=n;
    int answer=0;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(isPossible(arr,n,target,mid)){
            answer=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return answer;
}
