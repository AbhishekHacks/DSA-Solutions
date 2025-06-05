/*You are given an array of integers ARR[] of size N consisting of zeros and ones. You have to select a subset and flip bits of that subset. You have to return the count of maximum one’s that you can obtain by flipping chosen sub-array at most once.

A flip operation is one in which you turn 1 into 0 and 0 into 1.

For example:
If you are given an array {1, 1, 0, 0, 1} then you will have to return the count of maximum one’s you can obtain by flipping anyone chosen sub-array at most once, so here you will clearly choose sub-array from the index 2 to 3 and then flip it's bits. So, the final array comes out to be {1, 1, 1, 1, 1} which contains five ones and so you will return 5.*/

//Time Complexity -- O(n)

#include <bits/stdc++.h> 
int flipBits(int* arr, int n) 
{
    // WRITE YOUR CODE HERE
    int count_1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count_1+=1;
        }
    }
    int count_0=0;
    int maximum = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            count_0+=1;
        }
        else{
            count_0-=1;
        }
        if(count_0<0){
            count_0=0;
        }
        maximum = max(maximum,count_0);
    }
    return count_1+maximum;
}
