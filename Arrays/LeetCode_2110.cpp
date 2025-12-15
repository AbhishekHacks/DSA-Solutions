/*You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day.

A smooth descent period of a stock consists of one or more contiguous days such that the price on each day is lower than the price on the preceding day by exactly 1. The first day of the period is exempted from this rule.

Return the number of smooth descent periods.*/

//Time Complexity -- O(n)
//Space Complexity -- O(1)

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long count = 0;
        long long m = 1;
        for(int i=1;i<n;i++){
            if(prices[i-1]-prices[i]==1){
                m++;
            }
            else{
                count+=((m*(m-1))/2);
                m=1;
            }
        }
        count+=((m*(m-1))/2);
        return (count+n);
    }
};
