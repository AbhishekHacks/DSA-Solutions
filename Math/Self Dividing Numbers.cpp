/*A Ninja wants to collect all possible self-dividing numbers from a given range of numbers.

A self-dividing number is a number that is divisible by every digit it contains.

For example:
128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
Given a ‘LOWER’ and ‘UPPER’ number bound, your task is to find all possible self-diving numbers in the range of ‘LOWER’ to ‘UPPER’.

Note:
A self-dividing number is not allowed to contain the digit zero.*/

//Time Complexity -- O((upper-lower)*logn)

#include <bits/stdc++.h> 
vector < int > findAllSelfDividingNumbers(int lower, int upper) {
    // Write your code here
    vector<int>ans;
    for(int i=lower;i<=upper;i++){
        int num=i;
        bool isself = true;
        while(num>0){
            int r = num%10;
            if(r==0||i%r!=0){
                isself=false;
                break;
            }
            num/=10;
        }
        if(isself){
            ans.push_back(i);
        }
    }
    return ans;
}
