/*You are given a 2D array with dimensions ‘N*M’. You need to read the array elements row-wise and return a linear array that stores the elements like a wave i.e the 1st-row elements are stored from left to right, 2nd-row elements are stored from right to left, and so on.

*/

//Time Complexity -- O(n*m)

#include <bits/stdc++.h> 
vector<int> rowWaveForm(vector<vector<int>> &mat) {
    // Write your code here.
    int n = mat.size();
    int m = mat[0].size();
    vector<int>output;
    int count=0;
    for(int i=0;i<n;i++){
        if(count%2==0){
            for(int j=0;j<m;j++){
                output.push_back(mat[i][j]);
            }
        }
        else{
            for(int j=m-1;j>=0;j--){
                output.push_back(mat[i][j]);
            }
        }
        count++;
    }
    return output;
}
