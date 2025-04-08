/*Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
*/

//Time Complexity -- O(m+n)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        int rowIndex=0;
        int colIndex=n-1;
        while(rowIndex<m && colIndex>=0){
            int element = matrix[rowIndex][colIndex];
            if(element==target){
                return true;
            }
            else if(element>target){
                colIndex--;
            }
            else{
                rowIndex++;
            }
        }

        return false;
    }
};
