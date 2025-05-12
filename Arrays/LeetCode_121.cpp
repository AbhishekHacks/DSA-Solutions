/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/

//Time Complexity -- O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>suffix(n,0);
        int maximum = INT_MIN;
        for(int i=n-2;i>=0;i--){
            maximum = max(maximum,prices[i+1]);
            suffix[i]=maximum;
        }
        maximum = 0;
        for(int i=0;i<n-1;i++){
            if(suffix[i]>=prices[i]){
                int profit = suffix[i]-prices[i];
                maximum = max(maximum,profit);
            }
        }
        return maximum;
    }
};
