/*Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3x.*/

//Time Complexity -- O(log3(n))

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n>1){
            int r=n%3;
            if(r==2){
                return false;
            }
            n=n/3;
        }
        return true;
    }
};
