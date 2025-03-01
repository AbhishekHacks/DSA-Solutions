/*Our hero Teemo is attacking an enemy Ashe with poison attacks! When Teemo attacks Ashe, Ashe gets poisoned for a exactly duration seconds. More formally, an attack at second t will mean Ashe is poisoned during the inclusive time interval [t, t + duration - 1]. If Teemo attacks again before the poison effect ends, the timer for it is reset, and the poison effect will end duration seconds after the new attack.

You are given a non-decreasing integer array timeSeries, where timeSeries[i] denotes that Teemo attacks Ashe at second timeSeries[i], and an integer duration.

Return the total number of seconds that Ashe is poisoned.*/

//Time Complexity -- O(n)

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int totalTime=0;
        int i=1;
        int poisonstart=timeSeries[0];
        int poisonend=timeSeries[0]+duration-1;
        int nextpoisonstart=timeSeries[i];
        while(i<timeSeries.size()){
            if(nextpoisonstart<=poisonend){
                poisonend=nextpoisonstart+duration-1;
                i++;
                if(i>=timeSeries.size()){break;}
                nextpoisonstart=timeSeries[i];
            }
            else{
                totalTime+=poisonend-poisonstart+1;
                poisonstart=nextpoisonstart;
                poisonend=nextpoisonstart+duration-1;
                i++;
                if(i>=timeSeries.size()){break;}
                nextpoisonstart=timeSeries[i];
            }
        }
        totalTime+=poisonend-poisonstart+1;
        return totalTime;
    }
};
