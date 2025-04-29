/*You are given an array “ARR” of size N. Your task is to find out the sum of maximum and minimum elements in the array.

*/

//Time Complexity -- O(n)

#include <bits/stdc++.h> 
int sumOfMaxMin(int arr[], int n){
	// Write your code here.

	int minimum = INT_MAX;
	int maximum = INT_MIN;
	for(int i=0;i<n;i++){
		minimum=min(minimum,arr[i]);
		maximum=max(maximum,arr[i]);
	}

	return maximum+minimum;
}
