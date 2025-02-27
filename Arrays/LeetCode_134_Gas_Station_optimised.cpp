/*There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.*/

//Time Complexity -- O(n)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int i=0;
        while(i<n){
            int count=0;
            int g=0;
            int index=i;
            while(count<n){
                int c = cost[index%n];
                g+=gas[index%n];
                if(g>=c){
                    count++;
                    g-=c;
                    index++;
                }
                else{
                    i=index;
                    break;
                }
            }
            if(count==n){
                return i;
            }
            i++;
        }
        return -1;
    }
};
