/*You are given an integer ‘NUM’ . Your task is to find out whether this number is an Armstrong number or not.

A k-digit number ‘NUM’ is an Armstrong number if and only if the k-th power of each digit sums to ‘NUM’.

Example
153 = 1^3 + 5^3 + 3^3.

Therefore 153 is an Armstrong number.*/

#include <bits/stdc++.h> 
bool isArmstrong(int num) {
    // Write your code here
    int count=0;
    int n=num;
    int compare=num;
    while(n>0){
        count++;
        n=n/10;
    }
    long long sum=0;
    while(num>0){
        int r=num%10;
        sum+=pow(r,count);
        num=num/10;
    }
    if(compare==sum){
        return 1;
    }
    return 0;
}
