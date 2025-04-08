/*For a given two-dimensional integer array/list ‘ARR’ of size (N x M), print the ‘ARR’ in a sine wave order, i.e., print the first column top to bottom, next column bottom to top, and so on.

For eg:-

The sine wave for the matrix:-
1 2
3 4
will be [1, 3, 4, 2].
*/

//Time Compelxity -- O(n*m)

#include <bits/stdc++.h> 
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    //Write your code here

    vector<int>waves;

    for(int i=0;i<mCols;i++){
        for(int j=0;j<nRows;j++){
            if(i%2==0){
                waves.push_back(arr[j][i]);
            }
            else{
                waves.push_back(arr[nRows-1-j][i]);
            }
        }
    }

    return waves;
}
