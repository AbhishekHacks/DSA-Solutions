/*Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        map<pair<int,int>,int>m;
        for(auto pairs:dominoes){
            int x = pairs[0];
            int y = pairs[1];
            pair<int,int>p;
            p.first=min(x,y);
            p.second=max(x,y);
            m[p]++;
        }
        int count=0;
        for(auto i:m){
            int n = i.second;
            count+=(n*(n-1))/2;
        }
        return count;
    }
};
