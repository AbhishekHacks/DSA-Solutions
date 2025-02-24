/*You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?*/

//Time Complexity -- O(n)

class Solution {
public:
    int climbStairs(int n) {
        if(n==1||n==2){
            return n;
        }
        int a=1;
        int b=2;
        int c;
        for(int i=3;i<=n;i++){
            c = a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
