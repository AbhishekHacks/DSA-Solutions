/*Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.*/

//Time Complexity -- O(1)

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0){
            return false;
        }
        double x = log(n)/log(3);
        if(abs(x-round(x))<1e-10){
            return true;
        }
        return false;
    }
};
