/*Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.*/

//Time Complexity -- O(N^3)

class Solution {
public:

    bool isPossible(vector<vector<char>>& board,int row,int col){
        char ch = board[row][col];
        //row-wise checking
        for(int i=0;i<9;i++){
            if(i!=col){
                if(board[row][i]==ch){
                    return false;
                }
            }
        }
        //column-wise checking
        for(int i=0;i<9;i++){
            if(i!=row){
                if(board[i][col]==ch){
                    return false;
                }
            }
        }
        //square type checking
        int start_row = (row/3)*3;
        int start_col = (col/3)*3;
        for(int i=start_row;i<start_row+3;i++){
            for(int j=start_col;j<start_col+3;j++){
                if(i!=row||j!=col){
                    if(board[i][j]==ch){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!isPossible(board,i,j)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
