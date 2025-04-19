/*You are given a single non-negative integer ‘N’ who’s binary representation consists of a single ‘1’ digit and the rest of the digits are ‘0’s. Your task is to find the position of the only ‘1’ digit. In other words, your task is to find the position of the only set bit in the binary representation of the input integer ‘N’.

The position of the set bit must be counted from the LSB (Least Significant Bit) end of the Binary number. If the count of set bits in the Binary number is not equal to 1, then your function should return ‘-1’ as output.

Example:-
INPUT   : N = 4
OUTPUT  : 3*/

//Time Complexity -- O(logN)

#include <bits/stdc++.h> 
int findSetBit(int N) {   
    // Write your code here

    int pos=-1;
    int count=1;
    while(N>0){
        if((N&1)==1){
            if(pos==-1){
                pos=count;
            }
            else{
                return -1;
            }
        }
        N=N>>1;
        count+=1;
    }

    return pos;
}

