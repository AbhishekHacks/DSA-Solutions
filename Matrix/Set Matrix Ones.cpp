/*You have been given a non-empty grid ‘MAT’ consisting of only 0s and 1s. Your task is to modify it in such a way that if a cell has value 1 (MAT[i][j] == 1), then all the cells of the i-th row and j-th column should be changed to 1.

For Example
If the given grid is this:
[0, 0, 0]
[0, 0, 1]

Then the modified grid will be
[0, 0, 1],
[1, 1, 1]*/

//Time Complexity -- O(n*m*(n+m))

#include <bits/stdc++.h> 
void changematrix(vector<vector<int>> &MAT, int n, int m, int i, int j){
    //row
    for(int index=0;index<m;index++){
        MAT[i][index]=1;
    }
    //column
    for(int index=0;index<n;index++){
        MAT[index][j]=1;
    }
}
void setMatrixOnes(vector<vector<int>> &MAT, int n, int m)
{
    // Write your code here.
    vector<vector<int>>temp=MAT;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(temp[i][j]==1){
                changematrix(MAT,n,m,i,j);
            }
        }
    }
}
