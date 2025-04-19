/*You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.



You are also given an integer 'k' which denotes the number of aggressive cows.



You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.



Print the maximum possible minimum distance.

*/

//Time Complexity -- O(nlogn)

#include<bits/stdc++.h>

bool isPossible(vector<int> &stalls, int n, int k,int mid){
    int countcows=1;
    int pos=0;
    for(int i=1;i<n;i++){
        if((stalls[i]-stalls[pos])>=mid){
            pos=i;
            countcows++;
            if(countcows>=k){
                return true;
            }
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.

    //sort the stalls
    sort(stalls.begin(),stalls.end());

    int n = stalls.size();
    int start=1;
    int end = stalls[n-1]-stalls[0];
    int ans=-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(isPossible(stalls,n,k,mid)){
            ans = mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}
