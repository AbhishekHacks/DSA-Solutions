/*You are given an array 'ARR' consisting of 'N' non-negative integers, your task is to copy the elements of 'ARR' into another array 'COPY_ARR' in reverse order.

For example:

If 'ARR' contains the following elements [ 1, 2, 3, 4, 5 ], then you should return another array that is equal to [ 5, 4, 3, 2, 1].*/

//Time Complexity -- O(n)

#include <bits/stdc++.h> 
vector<int> copyAndReverse(vector<int> arr, int n) {
	// Write your code here.
	vector<int> rev;
	for(int i=arr.size()-1;i>=0;i--){
		rev.push_back(arr[i]);
	}
	return rev;
}
