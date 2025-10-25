/*Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.

He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, he will put in $1 more than the day before. On every subsequent Monday, he will put in $1 more than the previous Monday.

Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day.*/

//Time Complexity -- O(1)

class Solution {
public:
    int totalMoney(int n) {
        int first = ceil(n/7.0);
        int left_days = n%7;
        int days_money = (left_days/2.0)*((2*first)+(left_days-1));
        int week = n/7;
        int week_money = (week/2.0)*(56+((week-1)*7));
        return week_money+days_money;
    }
};
