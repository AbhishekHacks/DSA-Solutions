/*You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:

The digit sum of n (the sum of its digits).

The digit product of n (the product of its digits).

Return true if n is divisible by this sum; otherwise, return false.*/

//Time Complexity -- O(logn)

class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int sum = 0;
        int pro = 1;
        while(n>0){
            int r = n%10;
            sum+=r;
            pro*=r;
            n/=10;
        }
        int final_sum = sum+pro;
        if(num%final_sum==0){
            return true;
        }
        return false;
    }
};
