/*Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

*/

//Time Complexity -- O(n^2)

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        int count=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int a = dominoes[i][0];
                int b = dominoes[i][1];
                int c = dominoes[j][0];
                int d = dominoes[j][1];
                if(((a==c)&&(b==d))||((a==d)&&(b==c))){
                    count+=1;
                }
            }
        }
        return count;
    }
};
