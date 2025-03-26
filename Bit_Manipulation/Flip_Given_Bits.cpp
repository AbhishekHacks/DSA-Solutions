/*Problem statement
You have been given an integer 'NUM' (32 bits) and an array of size 'N'.

Your task is to flip all the bits of 'NUM' at position 'ARR[i]' where 0<= i <= N-1.*/

//Time Complexity -- O(N)

#include <bits/stdc++.h> 
int flipSomeBits(int num, vector<int> &arr, int n)
{
	// Write your code here.

	//just iterate the whole array and at each iteration just do the xor of num with pow(2,arr[i]-1)
	for(int i=0;i<n;i++){

		//xor of num with pow(2,arr[i]-1)
		int temp = pow(2,(arr[i]-1));
		num=num^temp;
	}

	//return the final number
	return num;
}
