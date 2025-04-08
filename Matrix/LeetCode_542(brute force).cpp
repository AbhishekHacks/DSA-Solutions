/*Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.*/

//Time Complexity -- O(n*m*n*m)

class Solution {
public:

    int nearest(vector<vector<int>>& mat,int n,int m,int row,int col){
        int dis = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    int d = abs(row-i)+abs(col-j);
                    if(dis>d){
                        dis=d;
                    }
                }
            }
        }

        return dis;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>output;

        for(int i=0;i<n;i++){
            vector<int>distance;
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    distance.push_back(0);
                }
                else{
                    int near = nearest(mat,n,m,i,j);
                    distance.push_back(near);
                }
            }
            output.push_back(distance);
        }

        return output;
    }
};
