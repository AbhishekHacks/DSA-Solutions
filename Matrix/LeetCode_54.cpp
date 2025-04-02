/*Given an m x n matrix, return all elements of the matrix in spiral order.*/

//Time Complexity -- O(n*m)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();
        
        //output vector
        vector<int>output;
        
        //count how many elements have been covered
        int count=0;

        //take a pointer row
        int row=0;

        //logic run an outer loop until count<n*m and than inside run 4 loops one for right , one for down , one for left and the other for up
        while(true){

            //right
            for(int i=row;i<m-row;i++){
                output.push_back(matrix[row][i]);
                count++;
            }

            //check if count == n*m
            if(count==(n*m)){
                break;
            }

            //down
            for(int j=1+row;j<n-row;j++){
                output.push_back(matrix[j][m-1-row]);
                count++;
            }

            //check if count == n*m
            if(count==(n*m)){
                break;
            }

            //left
            for(int k=m-2-row;k>=row;k--){
                output.push_back(matrix[n-1-row][k]);
                count++;
            }

            //check if count == n*m
            if(count==(n*m)){
                break;
            }

            //up
            for(int l=n-2-row;l>=1+row;l--){
                output.push_back(matrix[l][row]);
                count++;
            }

            //check if count == n*m
            if(count==(n*m)){
                break;
            }

            //increment row
            row++;
        }

        //return the output vector
        return output;
    }
};
