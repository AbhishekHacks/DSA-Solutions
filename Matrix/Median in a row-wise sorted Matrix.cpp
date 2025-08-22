/*Given a row-wise sorted matrix mat[][] of size n*m, where the number of rows and columns is always odd. Return the median of the matrix.*/

//Time Complexity -- O(n*mlog(n*m))

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        vector<int>elements;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                elements.push_back(mat[i][j]);
            }
        }
        sort(elements.begin(),elements.end());
        return elements[(m*n)/2];
    }
};
