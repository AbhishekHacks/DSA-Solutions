/*You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.*/

//Time Complexity -- O(n2)

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>v;
        int s=grid.size();
        int n =s*s;
        int true_sum=(n*(n+1))/2;
        int real_sum=0;
        unordered_map<int,int>m;
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                m[grid[i][j]]++;
                real_sum+=grid[i][j];
            }
        }
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                int diff = real_sum-grid[i][j];
                int key = true_sum-diff;
                if(key>=1 && key<=n && m.count(key)==0){
                    v.push_back(grid[i][j]);
                    v.push_back(key);
                    return v;
                }
            }
        }
        return v;
    }
};
