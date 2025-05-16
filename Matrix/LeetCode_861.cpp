/*You are given an m x n binary matrix grid.

A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including zero moves).*/

//Time Complexity -- O(m*n)

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //row
        for(int i=0;i<m;i++){
            if(grid[i][0]==0){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==0){
                        grid[i][j]=1;
                    }
                    else{
                        grid[i][j]=0;
                    }
                }
            }
        }
        //column
        for(int i=0;i<n;i++){
            int count_0=0;
            int count_1=0;
            for(int j=0;j<m;j++){
                if(grid[j][i]==0){
                    count_0+=1;
                }
                else{
                    count_1+=1;
                }
            }
            if(count_0>count_1){
                for(int j=0;j<m;j++){
                    if(grid[j][i]==0){
                        grid[j][i]=1;
                    }
                    else{
                        grid[j][i]=0;
                    }
                }
            }
        }
        //sum of numbers
        int result = 0;
        for(int i=0;i<m;i++){
            int number=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    number+=pow(2,n-1-j);
                }
            }
            result+=number;
        }
        return result;
    }
};
