/*You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.*/

//Time Complexity -- O(log(m*n))

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        int m = matrix[0].size();
        
        int start=0;
        int end =(n*m)-1;

        while(start<=end){
            int mid = start+(end-start)/2;
            int element = matrix[mid/m][mid%m];
            if(element==target){
                return true;
            }
            else if(element>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return false;
    }
};
