/*You are given a positive integer ‘N’. You have to check whether ‘N’ can be represented as a sum of two even numbers or not.

For example:
If the given number is 6, The number 6 can be represented as 2 + 4, and both 2 and 4 are even numbers. Hence the answer is “YES”.*/

//Time Complexity -- O(1)

#include <bits/stdc++.h> 
bool checkEvenPartitioning(int n) 
{
    // Write your code here
    //base case
    if(n==2){
        return false;
    }
    if(n%2==0){
        return 1;
    }
    return 0;
}

