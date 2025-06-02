/*Ninja is learning the binary representation of the numbers. He wanted to practice the topic, so he picked a question. The problem statement says, two numbers, ‘A’ and ‘B’ are given. Find the number of bits of ‘B’ that should be flipped to convert it into ‘A’.Can you help Ninja to solve this problem?

You are given two integers, ‘A’ and ‘B’.Find the number of bits of ‘B’ that should be flipped to convert it into ‘A’.

For Example
If ‘A’ is 13(1101) and ‘B’ is 7(0111), The number of bits that should be flipped is 2(0111). 
*/

//Time Complexity -- O(log(max(a,b)))

#include <bits/stdc++.h> 
int numberOfFlips(int a, int b)
{
    // Write your code here.
    int count=0;
    while(a>0||b>0){
        if((a&1)!=(b&1)){
            count+=1;
        }
        a=a>>1;
        b=b>>1;
    }
    return count;
}
