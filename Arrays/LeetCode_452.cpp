/*There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.*/

//Time Complexity -- O(NlogN)

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int n=points.size();

        //sort the input 2D vector points
        sort(points.begin(),points.end(),[](const vector<int>&a , const vector<int>&b){
            return a[1]<b[1];
        });

        //take two pointers to check if two intervals overlap
        int opening1=points[0][0];
        int closing1=points[0][1];

        //one variable 'count' to count the number of arrows to burst all the balloons
        int count=0;

        //iterate the array to check the intervals(overlapping)
        for(int i=1;i<n;i++){
            int opening2=points[i][0];
            int closing2=points[i][1];

            //check if one ,two or more balloons can be burst by an arrow
            if(opening2<=closing1){
                continue;
            }

            //if not , increase count
            else{
                count++; //one arrow shot
                opening1=opening2;
                closing1=closing2;
            }
        }

        //afterwards we see that there is still either one balloon left or overlapping balloons left , which can be shot by one arrow so we add one more arrow to our answer
        count+=1;

        //return the number of arrows shot
        return count;
    }
};
