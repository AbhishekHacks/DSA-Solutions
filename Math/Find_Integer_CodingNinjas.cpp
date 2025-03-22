/*You are given two integers, ‘N’ and ‘K’. Assume numbers from 1 to ‘N’ are arranged such that all odd numbers (in ascending order) are present first and then come to all even numbers (also in ascending order).

You need to find the integer at position ‘K’ (numbering of positions starts from 1).

For example:
You are given ‘N’ as 7 and ‘K’ as 4.  Numbers from 1 to 7 are arranged as [1, 3, 5, 7, 2, 4, 6], and the number at position 4 is 7. So, the answer is 7.*/

//Time Complexity -- O(1)

#include <bits/stdc++.h> 
int findInteger(int n, int k) 
{
    // Write your code here

    //check if k is in the range of even or odd
    if(k<=ceil((double)n/2)){
        
        //return the element at position k
        return 1+(k-1)*2;
    }

    //if not than in the range of odd
    else{

        //return the element at position k in the series 2,4,6,...
        int temp = k-ceil((double)n/2);
        return 2+(temp-1)*2;
    }

}
