/*Your friend Ninja has been learning about binary numbers lately. In order to understand binary numbers with perfection, Ninja asks you to generate a list of binary numbers from 1 to ‘N’, which he can use later for reference.

For every integer Ninja gives, your task is to generate all the binary numbers from 1 to ‘N’.

Example:

Consider N = 5,
All the binary numbers from 1 to 5 are: 1, 10, 11, 100, 101.*/

//Time Complexity -- O(nlogn)

#include <bits/stdc++.h> 
vector<string> generateBinaryNumbers(int n)
{
    // Write your code here.
    vector<string>ans;
    for(int i=1;i<=n;i++){
        string str;
        int num = i;
        while(num>0){
            int r = num%2;
            char ch = r+48;
            str.push_back(ch);
            num/=2;
        }
        reverse(str.begin(),str.end());
        ans.push_back(str);
    }
    return ans;
}
