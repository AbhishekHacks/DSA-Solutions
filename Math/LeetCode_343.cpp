/*Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.*/

//Time Complexity -- O(n)

class Solution {
public:
    int integerBreak(int n) {
        if(n==2||n==3){
            return n-1;
        }
        int count=0;
        while(n>3&&n!=4){
            n=n-3;
            count++;
        }
        return pow(3,count)*n;
    }
};
