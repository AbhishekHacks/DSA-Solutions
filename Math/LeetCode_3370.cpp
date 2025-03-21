/*You are given a positive number n.

Return the smallest number x greater than or equal to n, such that the binary representation of x contains only set bits

 */

//Time Complexity -- O(1)

class Solution {
public:
    int smallestNumber(int n) {
        int num = ceil(log(n+1)/log(2));
        int ans = pow(2,num);
        return ans-1;
    }
};
