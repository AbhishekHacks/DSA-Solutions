/*Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.*/

//Time Complexity -- O(1)

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1){
            return true;
        }
        double x = log(n)/log(4);
        if(fabs(x-round(x))<1e-10){
            return true;
        }
        return false;
    }
};
