/*Alice loves to give challenging tasks to Bob. This time, Alice gave Bob an array ‘A’ of ‘N’ distinct integers and asked him to find the maximum sum Bob can make by taking two elements from this array. To make this challenging, Alice asked Bob to find the answer by traversing the array only once.

As always, Bob asked you to help him do the task by traversing the array only once.*/

//Time Complexity -- O(n)

#include <bits/stdc++.h> 
int oneIteration(vector<int> A)
{
    // Write your code here.
    int first = A[0];
    int second = INT_MIN;
    int n = A.size();
    for(int i=1;i<n;i++){
        if(first<=A[i]){
            int temp = first;
            first = A[i];
            second = temp;
        }
        else{
            second = max(second,A[i]);
        }
    }
    return first+second;
}
