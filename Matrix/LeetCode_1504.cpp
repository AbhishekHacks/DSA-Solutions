/*Given an m x n binary matrix mat, return the number of submatrices that have all ones.*/

//Time Complexity -- O(m^3*n)

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
            for(int endRow=startRow;endRow<m;endRow++){
                vector<int>column;
                for(int col=0;col<n;col++){
                    bool satisfy = true;
                    for(int i=startRow;i<=endRow;i++){
                        if(mat[i][col]!=1){
                            satisfy = false;
                            break;
                        }
                    }
                    if(satisfy){
                        column.push_back(1);
                    }
                    else{
                        column.push_back(0);
                    }
                }
                result+=countsubarrays(column,n);
            }
        }
        return result;
    }
};
