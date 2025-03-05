/*Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.*/

//Time complexity -- O(logN)

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0){
            return false;
        }
        int count=0;
        while(n>0){
            int r = n%3;
            if(r==1){
                count+=1;
            }
            if(count>1||r==2){
                return false;
            }
            n=n/3;
        }
        return true;
    }
};
