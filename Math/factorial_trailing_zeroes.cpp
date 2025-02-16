/*Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.*/

// If the constraint is given as 0 <= n <= 10^4 than this is the best solution with O(1) time

class Solution {
public:
    int trailingZeroes(int n) {
        return n/3125+n/625+n/125+n/25+n/5;
    }
};
