/*You are given a sequence of only digits in the form of a string 'DIGIT_PATTERN', your task is to find the first repeating digit. If no digit is repeating you should return -1.

Example:

Given string of digits is 123456325. Now starting from the left, the first digit which is repeating is 3 as till 2nd 3 every digit is encountered 1st time and thus our answer for this input will be 3.*/

//Time Complexity -- O(n)

#include <bits/stdc++.h> 
int findFirstRepeatingDigit(string digitPattern) {
    // Write your code here.
    unordered_map<char,int>m;
    int n = digitPattern.size();
    for(int i=0;i<n;i++){
        if(m.count(digitPattern[i])){
            return digitPattern[i]-'0';
        }
        else{
            m[digitPattern[i]]++;
        }
    }
    return -1;
}
