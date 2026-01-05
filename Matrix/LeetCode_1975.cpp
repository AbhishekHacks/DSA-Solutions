/*You are given an n x n integer matrix. You can do the following operation any number of times:

Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.*/

//Time Complexity -- O(n^2)

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int negative = 0;
        bool zero_present = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    zero_present = true;
                }
                if(matrix[i][j]<0){
                    negative++;
                }
            }
        }
        long long sum = 0;
        int minimum = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=abs(matrix[i][j]);
                minimum = min(minimum,abs(matrix[i][j]));
            }
        }
        if((negative%2==0)||zero_present){
            return sum;
        }
        return sum-(2*minimum);
    }
};
