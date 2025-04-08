/*Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

*/

//Time Complexity -- O(n*m)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstrow=false;
        bool firstcol=false;
        //first row and first column
        for(int i=0;i<n;i++){
            if(matrix[0][i]==0){
                firstrow=true;
                break;
            }
        }
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                firstcol=true;
                break;
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int i=1;i<m;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            if(matrix[0][i]==0){
                for(int j=1;j<m;j++){
                    matrix[j][i]=0;
                }
            }
        }

        if(firstrow){
            for(int i=0;i<n;i++){
                matrix[0][i]=0;
            }
        }
        if(firstcol){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};
