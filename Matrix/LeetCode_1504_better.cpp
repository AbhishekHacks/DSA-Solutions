/*Given an m x n binary matrix mat, return the number of submatrices that have all ones.*/

//Time Complexity -- O(m*m*n)

class Solution {
public:

    int countsubarrays(vector<int>&column,int n){
        int count = 0;
        int output = 0;
        for(int i=0;i<n;i++){
            if(column[i]==1){
                count++;
            }
            else{
                output+=((count)*(count+1))/2;
                count=0;
            }
        }
        output+=((count)*(count+1))/2;
        return output;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int result = 0;
        for(int startRow=0;startRow<m;startRow++){
            vector<int>column(n,1);
            for(int endRow=startRow;endRow<m;endRow++){
                for(int col=0;col<n;col++){
                    column[col] = column[col]*mat[endRow][col];
                }
                result+=countsubarrays(column,n);
            }
        }
        return result;
    }
};
