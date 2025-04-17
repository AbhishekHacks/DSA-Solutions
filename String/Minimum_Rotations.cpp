/*You’re given a string 'S' of length 'N'. Your task is to find the minimum number of rotations to get the same string 'S'.

NOTE :
The string only consists of lowercase English alphabets.*/

//Time Complexity -- O(n^2)

#include <bits/stdc++.h> 
int minimumRotations(int n, string s)
{
	// Write your code here
	char ch = s.front();
	int count=0;
	for(int i=n-1;i>=0;i--){
		count++;
		if(s[i]==ch){
			string s1 = s.substr(i,n-i-2);
			string s2 = s.substr(0,i);
			string temp = s1.append(s2);
			if(temp==s){
				break;
			}
		}
	}
	return count;
}
