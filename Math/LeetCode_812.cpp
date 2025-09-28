/*Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.*/

//Time Complexity -- O(n^3)

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maximum = 0;
        for(int i=0;i<n;i++){
            double x2 = points[i][0];
            double y2 = points[i][1];
            for(int j=0;j<n;j++){
                if(j!=i){
                    double x3 = points[j][0];
                    double y3 = points[j][1];
                    double base = sqrt(pow((x3-x2),2)+pow((y3-y2),2));
                    for(int k=0;k<n;k++){
                        if(k!=i&&k!=j){
                            double x1 = points[k][0];
                            double y1 = points[k][1];
                            double h1 = sqrt(pow((x2-x1),2)+pow((y2-y1),2));
                            double h2 = sqrt(pow((x3-x1),2)+pow((y3-y1),2));
                            double x = (pow(h1,2)-pow(h2,2)+pow(base,2))/(2*base);
                            double height = sqrt(pow(h1,2)-pow(x,2));
                            double area = (0.5)*base*height;
                            maximum = max(maximum,area);
                        }
                    }
                }
            }
        }
        return maximum;
    }
};
