/*Given an integer numRows, return the first numRows of Pascal's triangle.*/
/*Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]*/

//Time Complexity -- O(numRows^2)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //Brute force -- O(n^2)
        vector<vector<int>> vec={{1}};
        if(numRows==1){
            return vec;
        }
        for(int i=2;i<=numRows;i++){
            vector<int> v;
            v.push_back(1);
            for(int j=1;j<i-1;j++){
                int temp = vec[i-2][j-1]+vec[i-2][j];
                v.push_back(temp);
            }
            v.push_back(1);
            vec.push_back(v);
        }
        return vec;
    }
};
