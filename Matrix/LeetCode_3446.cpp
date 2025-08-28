/*You are given an n x n square matrix of integers grid. Return the matrix such that:

The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
The diagonals in the top-right triangle are sorted in non-decreasing order.
*/

//Time Complexity -- O(n^2log(n))

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>temp;
        //bottom to top -- here i represents row
        for(int i=n-1;i>=0;i--){
            int j=i;
            int k=0;
            vector<int>curr_diag;
            while(j<n){
                curr_diag.push_back(grid[j][k]);
                j++;
                k++;
            }
            sort(curr_diag.begin(),curr_diag.end());
            reverse(curr_diag.begin(),curr_diag.end());
            temp.push_back(curr_diag);   
        }
        //left to right -- here i represents column
        for(int i=1;i<n;i++){
            int j=0;
            int k=i;
            vector<int>curr_diag;
            while(k<n){
                curr_diag.push_back(grid[j][k]);
                j++;
                k++;
            }
            sort(curr_diag.begin(),curr_diag.end());
            temp.push_back(curr_diag);
        }
        //lets fill each cell now
        int row=0;
        for(int i=n-1;i>=0;i--){
            int j=i;
            int k=0;
            int col=0;
            while(j<n){
                grid[j][k]=temp[row][col++];
                j++;
                k++;
            }
            row++;   
        }
        for(int i=1;i<n;i++){
            int j=0;
            int k=i;
            int col=0;
            while(k<n){
                grid[j][k]=temp[row][col++];
                j++;
                k++;
            }
            row++;
        }
        return grid;
    }
};
