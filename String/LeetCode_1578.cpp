/*Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.*/

//Time Complexity -- O(n)

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int i=0,j=1;
        int answer=0;
        while(j<n){
            if(colors[i]==colors[j]){
                if(neededTime[i]>neededTime[j]){
                    colors[j]='.';
                    answer+=neededTime[j];
                    j++;
                }
                else if(neededTime[i]<=neededTime[j]){
                    colors[i]='.';
                    answer+=neededTime[i];
                    i=j;
                    j++;
                }
            }
            else{
                i=j;
                j++;
            }
        }
        return answer;
    }
};
