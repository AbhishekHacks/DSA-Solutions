/*You are given two integer arrays prices and strategy, where:

prices[i] is the price of a given stock on the ith day.
strategy[i] represents a trading action on the ith day, where:
-1 indicates buying one unit of the stock.
0 indicates holding the stock.
1 indicates selling one unit of the stock.
You are also given an even integer k, and may perform at most one modification to strategy. A modification consists of:

Selecting exactly k consecutive elements in strategy.
Set the first k / 2 elements to 0 (hold).
Set the last k / 2 elements to 1 (sell).
The profit is defined as the sum of strategy[i] * prices[i] across all days.

Return the maximum possible profit you can achieve.

Note: There are no constraints on budget or stock ownership, so all buy and sell operations are feasible regardless of past actions.*/

//Time Complexity -- O(N)

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long>temp1;
        vector<long long>temp2;
        vector<long long>temp3;
        for(int i=0;i<n;i++){
            temp1.push_back(prices[i]*strategy[i]);
        }
        temp2.push_back(temp1[0]);
        for(int i=1;i<n;i++){
            temp2.push_back(temp1[i]+temp2[i-1]);
        }
        temp3.push_back(prices[0]);
        for(int i=1;i<n;i++){
            temp3.push_back(prices[i]+temp3[i-1]);
        }
        long long maximum = LLONG_MIN;
        for(int i=0;i<n-k+1;i++){
            long long temp = 0;
            if(i==0){
                temp = temp2[n-1]-temp2[i+k-1]+temp3[i+k-1]-temp3[i+((k-1)/2)];
            }
            else{
                temp = temp2[n-1]-temp2[i+k-1]+temp2[i-1]+temp3[i+k-1]-temp3[i+((k-1)/2)];
            }
            maximum = max(maximum,temp); 
        }
        return max(maximum,temp2[n-1]);
    }
};
