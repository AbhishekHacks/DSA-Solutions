/*You are given an array happiness of length n, and a positive integer k.

There are n children standing in a queue, where the ith child has happiness value happiness[i]. You want to select k children from these n children in k turns.

In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative and gets decremented only if it is positive.

Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        //Brute force -- O(nlogn)
        long long sum = 0;
        sort(happiness.begin(),happiness.end());
        int count = 0;
        for(int i=n-1;i>=0;i--){
            int num = happiness[i]-count;
            if(num>0){
                sum+=num;
                count++;
                if(count==k){
                    break;
                }
            }
            else{
                break;
            }
        }
        return sum;
    }
};
