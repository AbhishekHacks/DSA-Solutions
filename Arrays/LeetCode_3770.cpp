/*You are given an integer n.

Return the largest prime number less than or equal to n that can be expressed as the sum of one or more consecutive prime numbers starting from 2. If no such number exists, return 0.*/

//Time Complexity -- O(nloglogn)

class Solution {
public:
    int largestPrime(int n) {
        
        //sieve of eratosthenes
        vector<bool>isPrime(n+1,true);
        isPrime[0]=false;
        isPrime[1]=false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i){
                    isPrime[j] = false;
                }
            }
        }
        vector<int> primes;
        for (int i = 2; i <= n; i++){
            if (isPrime[i]){
                primes.push_back(i);
            }
        }

        int len = primes.size();
        long long sum = 0,maximum=0;
        for(int i=0;i<len;i++){
            sum+=primes[i];
            if(sum>n){
                return maximum;
            }
            if(isPrime[sum]){
                maximum=sum;
            }
        }
        return maximum;
    }
};
