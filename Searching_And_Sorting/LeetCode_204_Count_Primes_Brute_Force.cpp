/*Given an integer n, return the number of prime numbers that are strictly less than n.*/

//Time Complexity -- O(n^3/2)

class Solution {
public:
    int countPrimes(int n) {
        //Brute force 
        int count=0;
        for(int i=2;i<n;i++){
            int a=0;
            for(int j=2;j<=pow(i,0.5);j++){
                if(i%j==0){
                    a=1;
                    break;
                }
            }
            if(a==0){
                count++;
            }
        }
        return count;
    }
};
