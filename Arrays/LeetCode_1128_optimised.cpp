/*Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

*/

//Time Complexity -- O(n)

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        int count[100]={};
        for(auto i:dominoes){
            int x = min(i[0],i[1]);
            int y = max(i[0],i[1]);
            count[x*10+y]++;
        }
        int result=0;
        for(int i=0;i<100;i++){
            int n = count[i];
            result+=(n*(n-1))/2;
        }
        return result;
    }
};
