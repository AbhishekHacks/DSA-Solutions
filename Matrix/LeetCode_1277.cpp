/*Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.*/

//Time Complexity -- O(min(m,n)*m*n)

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    for(int k=1;k<=min(m,n);k++){
                        bool satisfy = true;
                        int row1 = i; 
                        int col1 = j+k-1;
                        int row2 = i+k-1;
                        int col2 = j;
                        if(row2>=m||col1>=n){
                            break;
                        }
                        while(row1<=row2&&col2<=col1){
                            if(matrix[row1][col1]!=1||matrix[row2][col2]!=1){
                                satisfy = false;
                                break;
                            }
                            row1++;
                            col2++;
                        }
                        if(!satisfy){
                            break;
                        }
                        count+=1;
                    }
                }
            }
        }
        return count;
    }
};
