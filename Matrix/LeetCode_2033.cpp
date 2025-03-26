/*You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

A uni-value grid is a grid where all the elements of it are equal.

Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.*/

//Time Complexity -- O(m*n)

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        int m=grid.size();
        int n=grid[0].size();
        
        //store the 2D matrix inside a 1D vector
        vector<int>v;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v.push_back(grid[i][j]);
            }
        }

        //sort the vector for the median
        sort(v.begin(),v.end());

        //size of the vector
        int s = m*n;

        //calculate the median
        int median = v[s/2];

        //lets calculate the absolute difference between each element to median and than check whether the absolute difference is divisible by x
        //if divisible,calculate absolute difference/x and add it to answer
        //if no,return -1
        int ans=0;
        for(int i=0;i<s;i++){
            int difference = abs(v[i]-median);
            if(difference%x!=0){
                return -1;
            }
            int operation = difference/x;
            ans+=operation; //store the total operations in ans
        }

        //return the total operations
        return ans;
    }
};
