/*The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).*/

//Time Complexity -- O(N)

class Solution {
public:
    int fib(int n) {
        
        //check for edge cases
        if(n==0||n==1){
            return n;
        }

        //intialise the first two fibonacci numbers
        int a=0;
        int b=1;

        //calculate the nth fibonacci number
        int c=0;
        for(int i=2;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }

        //return the nth fibonacci number
        return c;
    }
};
