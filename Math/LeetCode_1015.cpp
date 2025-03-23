/*Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.

Return the length of n. If there is no such n, return -1.

Note: n may not fit in a 64-bit signed integer.*/

//Time Complexity -- O(k)

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        
        //take variable length to calculate the length of the number
        int length=1;

        //the remainder be 1
        int rem=1%k;

        //until the remainder becomes 0 add 1s in the remainder and increase length
        while(rem!=0&&length<=k){
            rem=(rem*10)+1;
            length++;
            rem=rem%k;
        }

        //if length>k return -1
        if(length>k){
            return -1;
        }

        //return the length
        return length;
    }
};
