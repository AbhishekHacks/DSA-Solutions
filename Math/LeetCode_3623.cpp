/*You are given a 2D integer array points, where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.

A horizontal trapezoid is a convex quadrilateral with at least one pair of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they have the same slope.

Return the number of unique horizontal trapezoids that can be formed by choosing any four distinct points from points.

Since the answer may be very large, return it modulo 109 + 7.*/

//Time Complexity -- O(n)

class Solution {
public:
    int calculate(int x){
        if(x<2){
            return 0;
        }
        return (((long long)(x-1)*x)/2)%1000000007;
    }
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[points[i][1]]++;
        }
        int len = m.size();
        vector<int>suffix(len,0);
        vector<int>points_y;
        for(auto i:m){
            points_y.push_back(i.first);
        }
        suffix[len-1]=calculate(m[points_y[len-1]]);
        for(int i=len-2;i>=1;i--){
            suffix[i] = suffix[i+1]+calculate(m[points_y[i]]);
        }
        long long answer = 0;
        for(int i=0;i<len-1;i++){
            answer+=((long long)calculate(m[points_y[i]])*suffix[i+1])%1000000007;
        }
        return answer%1000000007;
    }
};
