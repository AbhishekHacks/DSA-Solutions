/*You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.*/

//Time Complexity -- O(n)

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()==2){
            return 1;
        }
        //condition for the y-axis
        int a=0;
        for(int i=0;i<coordinates.size();i++){
            if(coordinates[i][0]!=0){
                a=1;
                break;
            }
        }
        if(a==0){
            return true;
        }
        int x1=coordinates[0][0];
        int y1=coordinates[0][1];
        int x2=coordinates[1][0];
        int y2=coordinates[1][1];
        double prev = (double)(y2-y1)/(x2-x1);
        for(int i=2;i<coordinates.size();i++){
            x1=coordinates[i-1][0];
            y1=coordinates[i-1][1];
            x2=coordinates[i][0];
            y2=coordinates[i][1];
            double slope = (double)(y2-y1)/(x2-x1);
            if(slope!=prev){
                return false;
            }
            prev=slope;
        }
        return true;
    }
};
