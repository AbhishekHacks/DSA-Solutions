/*In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

*/

//Time Complexity -- O(n^2)

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int n = mat.size();
        int m = mat[0].size();

        if((n*m)!=(r*c)){
            return mat;
        }

        vector<vector<int>>output;
        int count=0;
        vector<int>temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp.push_back(mat[i][j]);
                count+=1;
                if(count==c){
                    output.push_back(temp);
                    temp.clear();
                    count=0;
                }
            }
        }
        return output;
    }
};
