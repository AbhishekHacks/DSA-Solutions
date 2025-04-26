/*You are given a three integers 'X', 'N', and 'M'. Your task is to find ('X' ^ 'N') % 'M'. A ^ B is defined as A raised to power B and A % C is the remainder when A is divided by C.*/

//Time Complexity -- O(logN)

#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here.

	int res=1;
	x=x%m;
	if(x==0){
		return 0;
	}
	while(n>0){
		if(n&1){
			res=((long long)res*x)%m;
		}
		n=n>>1;
		x=((long long)x*x)%m;
	}

	return res;
}
