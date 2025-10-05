/*There is a rectangular brick wall in front of you with n rows of bricks. The ith row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths. The total width of each row is the same.

Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.

Given the 2D array wall that contains the information about the wall, return the minimum number of crossed bricks after drawing such a vertical line.*/

//Time Complexity -- O(n^2)

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long,int>m;
        int n = wall.size();
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=0;j<wall[i].size()-1;j++){
                sum+=wall[i][j];
                m[sum]++;
            }
        }
        int maximum = 0;
        for(auto i:m){
            maximum=max(maximum,i.second);
        }
        return n-maximum;
    }
};
