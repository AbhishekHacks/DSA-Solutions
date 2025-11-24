/*You are given a positive integer n.

Let s be the binary representation of n without leading zeros.

The reverse of a binary string s is obtained by writing the characters of s in the opposite order.

You may flip any bit in s (change 0 → 1 or 1 → 0). Each flip affects exactly one bit.

Return the minimum number of flips required to make s equal to the reverse of its original form.*/

//Time Complexity -- O(logn)

class Solution {
public:
    int minimumFlips(int n) {
        string s;
        while(n>0){
            s.push_back((n&1)+'0');
            n=n>>1;
        }
        int i=0,j=s.size()-1,count=0;
        while(i<j){
            if(s[i]!=s[j]){
                count+=2;
            }
            i++;
            j--;
        }
        return count;
    }
};
