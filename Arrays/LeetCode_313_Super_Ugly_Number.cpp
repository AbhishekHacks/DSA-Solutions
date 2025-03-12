/*A super ugly number is a positive integer whose prime factors are in the array primes.

Given an integer n and an array of integers primes, return the nth super ugly number.

The nth super ugly number is guaranteed to fit in a 32-bit signed integer.*/

//Brute force approach 

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        //nth ugly number -- brute force
        int s = primes.size();
        int count = 0;
        int ans = 0;
        for(int num=1;num<=INT_MAX;num++){
            int element = num;
            int i=0;
            while(element>1){
                if(element%primes[i]==0){
                    element=element/primes[i];
                }
                else{
                    i++;
                    if(i>=s){
                        break;
                    }
                }
            }
            if(element==1){
                count++;
                if(count==n){
                    ans=num;
                    break;
                }
            }
        }
        return ans;  
    }
};
