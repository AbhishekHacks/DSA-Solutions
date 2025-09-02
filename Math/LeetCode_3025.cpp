/*You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D plane, where points[i] = [xi, yi].

Count the number of pairs of points (A, B), where

A is on the upper left side of B, and
there are no other points in the rectangle (or line) they make (including the border).
Return the count.*/

//Time Complexity -- O(n^3)

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        //the outer loop represents the point B
        //the first inner loop represents the point A
        //the last inner loop is to check whether the points lie between points A and B
        //concept - 1 --> A should be on the upper left side of B
        int count=0;
        for(int i=0;i<n;i++){ //B
            for(int j=0;j<n;j++){ //A
                if(i!=j&&points[j][0]<=points[i][0]&&points[j][1]>=points[i][1]){ //A and B not equal
                    bool lies = false;
                    for(int k=0;k<n;k++){
                        if(k!=i&&k!=j){ //points not equal to A and B
                            if(points[k][0]>=points[j][0]&&points[k][0]<=points[i][0]&&points[k][1]>=points[i][1]&&points[k][1]<=points[j][1]){
                                lies = true;
                                break;
                            }
                        }
                    }
                    if(!lies){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
