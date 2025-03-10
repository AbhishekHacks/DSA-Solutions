/*You have been given an integer 'NUM' (32 bits) and an array of size 'N'.

Your task is to flip all the bits of 'NUM' at position 'ARR[i]' where 0<= i <= N-1.*/

//Time Complexity -- O(n)

#include <bits/stdc++.h> 
int flipSomeBits(int num, vector<int> &arr, int n)
{
	// Write your code here.
	for(int i=0;i<n;i++){
		int power = pow(2,(arr[i]-1));
		num=num^power;
	}
	return num;
}
