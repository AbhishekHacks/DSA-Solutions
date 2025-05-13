/*You have an integer array ‘A’ of the form of [x, x+1, x+2, x+3, …….]. As the array is vast in size, you are given both endpoints of the array, i.e., If you are given two integers, ‘L’ and ‘R’, the array ‘A’ will be [L, L+1, L+2, ……., R-1, R]. Your task is to find the maximum possible value of ‘X’ such that the following two conditions hold.

a ⊕ b = X, where ⊕ denotes bitwise xor operation.
Both numbers ‘a’ and ‘b’ belong to the array ‘A’.*/

//Time Complexity -- O(log(L^R))

#include <bits/stdc++.h> 
int maxXor(int L, int R)
{
    // Write your code here.
    int bitwise_xor = L^R;
    int count=1;
    int bit = 0;
    while(bitwise_xor>0){
        if((bitwise_xor&1)==1){
            bit=count;
        }
        bitwise_xor=bitwise_xor>>1;
        count+=1;
    }
    return pow(2,bit)-1;
}
