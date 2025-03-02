/*Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.*/

//Time Complexity -- O(log2n)

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }
        if(n==1){
            return true;
        }
        int count_0=0;
        int count_1=0;
        while(n>0){
            if((n&1)==0){
                count_0+=1;
            }
            else{
                count_1+=1;
            }
            n=n>>1;
        }
        if(count_0%2==0&&count_1==1){
            return true;
        }
        return false;
    }
};
