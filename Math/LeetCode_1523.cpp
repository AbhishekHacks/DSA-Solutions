/*Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).*/

//Time Complexity -- O(1)

class Solution {
public:
    int countOdds(int low, int high) {
        int ans = (high-low)/2;
        if((low%2==0)&&(high%2==0)){
            return ans;
        }
        return ans+1;
    }
};
