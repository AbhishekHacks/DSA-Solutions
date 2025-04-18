/*Ninja has been provided a matrix 'MAT' of size 'N X M' where 'M' is the number of columns in the matrix, and 'N' is the number of rows.

The weight of the particular row is the sum of all elements in it. Ninja wants to find the maximum weight amongst all the rows.

Your task is to help the ninja find the maximum weight amongst all the rows.

EXAMPLE:
Input: 'N' = 2, 'M' = 3, 'MAT' = [[1, 2, 3], [2, 0, 0]]
Output: 6

The weight of first row is 1 + 2 + 3 = 6
The weight of the second row is 2 + 0 + 0 = 2; hence the answer will be a maximum of 2 and 6, which is 6.
*/

//Time Complexity -- O(n*m)

#include <bits/stdc++.h> 
int maximumWeightRow(int n, int m, vector<vector<int>> &mat) {
    // Write your code here.

    int maximum = INT_MIN;

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            sum+=mat[i][j];
        }
        if(maximum<sum){
            maximum=sum;
        }
    }

    return maximum;
}
