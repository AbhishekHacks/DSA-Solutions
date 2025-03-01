/*Given an integer n, return the number of prime numbers that are strictly less than n.*/

//Time Complexity -- O(NlogNlogN)

class Solution {
public:
    int countPrimes(int n) {
        //optimise
        if(n==0||n==1){
            return 0;
        }
        vector<bool> v(n,true);
        v[0]=false;
        v[1]=false;
        int count=0;
        for(int i=2;i<n;i++){
            if(v[i]==true){
                count++;
                int mult=2;
                while(i*mult<n){
                    v[i*mult]=false;
                    mult++;
                }
            }
        }
        return count;
    }
};
