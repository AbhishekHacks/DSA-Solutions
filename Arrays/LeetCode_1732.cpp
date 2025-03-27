/*There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.*/

//Time Complexity -- O(N)

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int n = gain.size();

        //declare a 'highest' variable to store the highest altitude
        int highest=INT_MIN;

        //take a variable 'sum' to store the sum of points of different altitudes and than store the highest sum in variable 'highest'
        int sum=0;

        //iterate the array
        for(int i=0;i<n;i++){
            sum+=gain[i];
            if(highest<sum){
                highest=sum;
            }
        }

        //before returning the answer , note that we still did not consider a 0 in the beginning , if a sum comes as negative and it is the highest than the first point 0 could be the highest altitude so return the max of 0 and highest

        highest = max(0,highest);

        //return the highest altitude
        return highest;
    }
};
