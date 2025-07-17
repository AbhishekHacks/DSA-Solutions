/*Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.*/

//Time Complexity -- O(m*n)

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>diagonal;
        for(int row=0;row<m;row++){
            int i=row;
            int j=0;
            vector<int>temp;
            while(i>=0&&j<=n-1){
                temp.push_back(mat[i][j]);
                i--;
                j++;
            }
            diagonal.push_back(temp);
        }
        int row = m-1;
        int col = 1;
        while(col<=n-1){
            int i = row;
            int j = col;
            vector<int>temp;
            while(i>=0&&j<=n-1){
                temp.push_back(mat[i][j]);
                i--;
                j++;
            }
            diagonal.push_back(temp);
            col++;
        }
        int a=0;
        vector<int>output;
        int len = diagonal.size();
        for(int i=0;i<len;i++){
            int size = diagonal[i].size();
            for(int j=0;j<size;j++){
                if(a%2==0){
                    output.push_back(diagonal[i][j]);
                }
                else{
                    output.push_back(diagonal[i][size-1-j]);
                }
            }
            a++;
        }
        return output;
    }
};
