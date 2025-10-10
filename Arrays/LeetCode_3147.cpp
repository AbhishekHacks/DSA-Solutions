/*In a mystic dungeon, n magicians are standing in a line. Each magician has an attribute that gives you energy. Some magicians can give you negative energy, which means taking energy from you.

You have been cursed in such a way that after absorbing energy from magician i, you will be instantly transported to magician (i + k). This process will be repeated until you reach the magician where (i + k) does not exist.

In other words, you will choose a starting point and then teleport with k jumps until you reach the end of the magicians' sequence, absorbing all the energy during the journey.

You are given an array energy and an integer k. Return the maximum possible energy you can gain.

Note that when you are reach a magician, you must take energy from them, whether it is negative or positive energy.*/

//Time Complexity -- O(n)

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int maximum = INT_MIN;
        for(int i=0;i<n;i++){
            if(energy[i]!=INT_MIN){
                int sum1=0,sum2=0;
                int j1=i;
                while(j1<n){
                    sum1+=energy[j1];
                    j1+=k;
                }
                maximum=max(maximum,sum1);
                int j2=i;
                while(j2<(j1-k)){
                    sum2+=energy[j2];
                    energy[j2]=INT_MIN;
                    maximum=max(maximum,sum1-sum2);
                    j2+=k;
                }
            }
        }
        return maximum;
    }
};
