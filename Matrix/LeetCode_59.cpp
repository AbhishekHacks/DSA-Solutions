/*Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.*/

//Time Complexity -- O(N^2)

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        int size = n*n;
        int arr[n][n];

        //code for spiral matrix
        int row=0;
        int count=1;
        while(true){

            //right
            for(int i=row;i<n-row;i++){
                arr[row][i]=count;
                count+=1;
            }

            if(count>size){
                break;
            }

            //down
            for(int j=1+row;j<n-row;j++){
                arr[j][n-1-row]=count;
                count+=1;
            }

            if(count>size){
                break;
            }

            //left
            for(int k=n-2-row;k>=row;k--){
                arr[n-1-row][k]=count;
                count+=1;
            }

            if(count>size){
                break;
            }

            //up
            for(int l=n-2-row;l>=1+row;l--){
                arr[l][row]=count;
                count+=1;
            }

            if(count>size){
                break;
            }

            //increment row
            row++;
        }

        //create the 2D vector
        vector<vector<int>>output;

        //copy the elements of arr in output
        for(int i=0;i<n;i++){
            vector<int>element;
            for(int j=0;j<n;j++){
                element.push_back(arr[i][j]);
            }
            output.push_back(element);
        }

        //return the output
        return output;
    }
};
