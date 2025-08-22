/*You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.

Return the minimum possible area of the rectangle.*/

//Time Complexity -- O(m*n)

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //startRow and endRow
        int startRow=-1,endRow=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(startRow==-1){
                        startRow=i;
                    }
                    endRow=i;
                    break;
                }
            }
        }
        //start column and end colun
        int startCol = -1,endCol = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[j][i]==1){
                    if(startCol==-1){
                        startCol=i;
                    }
                    endCol=i;
                    break;
                }
            }
        }
        //area of this rectangle
        return (endCol-startCol+1)*(endRow-startRow+1);
    }
};
