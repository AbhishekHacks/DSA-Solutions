/*Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.*/

//Another solution with O(n*log5(n)) time complexity

class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        for(int i=0;i<=n;i+=5){
            int element=i;
            while(element>0&&element%5==0){
                count++;
                element/=5;
            }
        }
        return count;
    }
};
