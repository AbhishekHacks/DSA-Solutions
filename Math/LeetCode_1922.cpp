/*A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.*/

//Time Complexity -- O(logn)

class Solution {
public:
    int countGoodNumbers(long long n) {
        long long count_even = ceil((double)n/2);
        long long count_odd = floor((double)n/2);
        long long ans1 = 1;
        long long x1 = 5;
        while(count_even>0){
            if(count_even%2==0){
                x1=(x1*x1)%1000000007;
                count_even/=2;
            }
            else{
                ans1=(ans1*x1)%1000000007;
                count_even--;
            }
        }
        long long ans2 = 1;
        long long x2 = 4;
        while(count_odd>0){
            if(count_odd%2==0){
                x2=(x2*x2)%1000000007;
                count_odd/=2;
            }
            else{
                ans2=(ans2*x2)%1000000007;
                count_odd--;
            }
        }
        return (ans1*ans2)%1000000007;
    }
};
