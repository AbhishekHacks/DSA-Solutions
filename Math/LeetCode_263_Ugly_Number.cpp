/*An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5.

Given an integer n, return true if n is an ugly number.*/

//Time Complexity -- O(log2(n)log3(n)log5(n))

class Solution {
public:
    bool isUgly(int n) {
        if(n<=0){
            return false;
        }
        while(n>1){
            if(n%2==0){
                n=n/2;
            }
            else if(n%3==0){
                n=n/3;
            }
            else if(n%5==0){
                n=n/5;
            }
            else{
                break;
            }
        }
        return n==1;
    }
};
