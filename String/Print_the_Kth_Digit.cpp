/*You are given three non-negative integers N, M, and K. Your task is to print the Kth digit from the right in ‘N’ raised to the power ‘M’ that is, in N ^ M.

Note:

1) It is guaranteed that the Kth digit from the right always exists.
2) It is also guaranteed that 'K' is always less than or equal to the number of digits in N ^ M.
3) 'N' and 'M 'can’t be a 0 simultaneously.*/

//Time Complexity -- O(1)

#include <bits/stdc++.h> 
int findKthFromRight(int n, int m, int k) 
{
	// Write your code here.

	long long number = pow(n,m);

	string s = to_string(number);

	int answer = s[s.size()-k]-'0';

	return answer;
}
