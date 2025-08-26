/*You are given a 2D 0-indexed integer array dimensions.

For all indices i, 0 <= i < dimensions.length, dimensions[i][0] represents the length and dimensions[i][1] represents the width of the rectangle i.

Return the area of the rectangle having the longest diagonal. If there are multiple rectangles with the longest diagonal, return the area of the rectangle having the maximum area.*/

//Time Complexity -- O(n)

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        double maximum = DBL_MIN;
        int area = INT_MIN;
        int answer=0;
        for(int i=0;i<n;i++){
            int a = dimensions[i][0]*dimensions[i][1];
            int d = pow(dimensions[i][0],2)+pow(dimensions[i][1],2);
            double sq = sqrt(d);
            if(maximum<sq){
                maximum=sq;
                answer=a;
            }
            else if(maximum==sq){
                answer=max(answer,a);
            }
        }
        return answer;
    }
};
