/*You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

*/

//Time Complexity -- O(n*n)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        //transpose of the matrix
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int temp = matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }

        //reverse the columns
        int i=0;
        int j=n-1;
        while(i<j){
            for(int k=0;k<n;k++){
                int temp = matrix[k][i];
                matrix[k][i]=matrix[k][j];
                matrix[k][j]=temp;
            }
            i++;
            j--;
        }
    }
};
