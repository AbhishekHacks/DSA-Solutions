/*You are given integers n, m, and k.

There are two logs of lengths n and m units, which need to be transported in three trucks where each truck can carry one log with length at most k units.

You may cut the logs into smaller pieces, where the cost of cutting a log of length x into logs of length len1 and len2 is cost = len1 * len2 such that len1 + len2 = x.

Return the minimum total cost to distribute the logs onto the trucks. If the logs don't need to be cut, the total cost is 0.*/

//Time Complexity -- O(1)

class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long answer=0;
        int log1 = n-k;
        if(log1>0){
            answer+=(long long)k*(n-k);
        }
        int log2 = m-k;
        if(log2>0){
            answer+=(long long)k*(m-k);
        }
        return answer;
    }
};
