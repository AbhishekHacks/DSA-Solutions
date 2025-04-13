/*You have been given an array/list ‘A’ consisting of ‘N’ integers all of which are ‘0’ initially. You are given an array/list ‘ARR’ consisting of ‘M’ pairs of integers which are ‘M’ operations you need to perform on ‘A’. In each operation, you are given a range and you need to increase each element whose index lies in that range by ‘1’. Your task is to return the maximum element of array/list ‘A’ after all ‘M’ operations are performed.*/
//Time Complexity -- O(n^2)

#include <bits/stdc++.h> 
int findMaxElement(vector < pair < int, int > > & arr, int n, int m) {
    // Write Your Code here. 

    vector<int>a(n,0);
    for(int i=0;i<m;i++){
        int start = arr[i].first;
        int end = arr[i].second;
        for(int j=start-1;j<end;j++){
            a[j]=a[j]+1;
        }
    }
    int highest = 0;
    for(int i=0;i<n;i++){
        if(highest<a[i]){
            highest = a[i];
        }
    }
    return highest;
}
