/*You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:

Each of the two resulting sections formed by the cut is non-empty.
The sum of the elements in both sections is equal.
Return true if such a partition exists; otherwise return false.*/

//Time Complexity -- O(n*m)

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        long long sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
            }
        }
        if(n!=1){
            //horizontally
            long long row_sum = 0;
            for(int i=0;i<n-1;i++){
                for(int j=0;j<m;j++){
                    row_sum+=grid[i][j];
                }
                long long rem_sum = sum-row_sum;
                if(rem_sum==row_sum){
                    return true;
                }
            }
        }
        if(m!=1){
            //vertically
            long long col_sum = 0;
            for(int i=0;i<m-1;i++){
                for(int j=0;j<n;j++){
                    col_sum+=grid[j][i];
                }
                long long rem_sum = sum-col_sum;
                if(rem_sum==col_sum){
                    return true;
                }
            }
        }
        return false;
    }
};
