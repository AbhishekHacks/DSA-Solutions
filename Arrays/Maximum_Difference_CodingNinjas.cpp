/*You are given an array 'ARR' of the 'N' element. Your task is to find the maximum difference between any of the two elements from 'ARR'.

If the maximum difference is even print “EVEN” without quotes. If the maximum difference is odd print “ODD” without quotes.

For example:

Given 'ARR' = [1, 10, 5, 2, 8, 1 ] , answer is "ODD".
Here the maximum difference is between 10 and 1, 10 - 1 = 9*/

//Time Complexity -- O(N)

#include <bits/stdc++.h> 
string maximumDifference(int n, vector<int>& arr)
{
	// Write your code here.
	int max=INT_MIN;
	int min=INT_MAX;
	for(int i=0;i<n;i++){
		if(max<arr[i]){
			max=arr[i];
		}
		if(min>arr[i]){
			min=arr[i];
		}
	}
	int diff = max - min;
	if(diff%2==0){
		return "EVEN";
	}
	return "ODD";
}
