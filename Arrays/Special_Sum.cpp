/*You are given an array ‘ARR’ of length ‘N’. There are two operations, ‘FIRST_SUM’ and ‘LAST_SUM’ for every index ‘i’ (1 <= i <= N) in the array,

i) FIRST_SUM(i) calculates the sum of first i numbers.

ii) LAST_SUM(i) calculates the sum of last N-i+1 numbers.

Also for every ‘i’, SPECIAL_SUM(i) can be calculated as:

SPECIAL_SUM(i) = FIRST_SUM(i) + LAST_SUM(i)

Your task is to return the minimum SPECIAL_SUM for 0 <= i <= N - 1.

For example:

Given ‘N’ = 4 and ‘ARR’ = [1, 2, 3, 4].
Then the minimum special sum will be 5 for i = 0 (0-based indexing), which is (1 + 4) = 5.Sum of 1 integer from beginning and end.
For i = 1 it will be (1 + 2) + (3 + 4) = 10
For i = 2 it will be (1 + 2 + 3) + (2 + 3 + 4) = 15
For i = 3 it will be (1 + 2 + 3 + 4) + (1 + 2 + 3 + 4) = 20
All of which are greater than 5.  */

//Time Complexity -- O(N)

#include <bits/stdc++.h> 
int specialSum(vector<int> &arr, int n)
{
	// Write your code here. 

	vector<int>prefix(n,0);
	vector<int>suffix(n,0);
	int prefix_sum=0;
	for(int i=0;i<n;i++){
		prefix_sum+=arr[i];
		prefix[i]=prefix_sum;
	}
	int suffix_sum=0;
	for(int i=n-1;i>=0;i--){
		suffix_sum+=arr[i];
		suffix[i]=suffix_sum;
	}
	int result = INT_MAX;
	for(int i=0;i<n;i++){
		int special_sum = prefix[i]+suffix[n-1-i];
		result = min(result,special_sum);
	}
	return result;
}
