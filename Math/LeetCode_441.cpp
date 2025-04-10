/*You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.

 

*/

//Time Complexity -- O(1)

class Solution {
public:
    int arrangeCoins(int n) {
        
        long long mult = (long long)8*n;
        int sq = sqrt(1+mult);
        return (sq-1)/2;
    }
};
