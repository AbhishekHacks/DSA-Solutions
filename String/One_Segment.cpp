/*You are given a binary string ‘STR’, containing only zeroes and ones. This string does not contain any leading zero.

Your task is to determine if this string contains at most one contiguous segment of ones.*/

//Time Complexity -- O(n)

#include <bits/stdc++.h> 
bool oneSegment(string str) {
	// Write your code here.

	int n = str.size();
	int count=0;
	int temp=0;

	for(int i=0;i<n;i++){
		if(str[i]=='1'&&count==0){
			count=1;
		}
		else if(str[i]=='0'){
			temp+=count;
			count=0;
		}
	}

	temp+=count;

	if(temp<=1){
		return true;
	}
	return false;
}
