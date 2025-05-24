/*Given a string s, find the sum of the 3 largest unique prime numbers that can be formed using any of its substrings.

Return the sum of the three largest unique prime numbers that can be formed. If fewer than three exist, return the sum of all available primes. If no prime numbers can be formed, return 0.

A prime number is a natural number greater than 1 with only two factors, 1 and itself.

A substring is a contiguous sequence of characters within a string.

Note: Each prime number should be counted only once, even if it appears in multiple substrings. Additionally, when converting a substring to an integer, any leading zeros are ignored.

*/

//Time Complexity -- O(n^(5/2))

class Solution {
public:

    bool isPrime(long long number){
        if(number==0||number==1){
            return false;
        }
        for(int i=2;i<=sqrt(number);i++){
            if(number%i==0){
                return false;
            }
        }
        return true;
    }
    
    long long sumOfLargestPrimes(string s) {
        int n = s.size();
        vector<long long>prime;
        for(int i=0;i<n;i++){
            long long number = 0;
            for(int j=i;j<n;j++){
                int r = s[j]-'0';
                number=(number*10)+r;
                if(isPrime(number)){
                    prime.push_back(number);
                }
            }
        }
        sort(prime.begin(),prime.end());
        int sv = prime.size();
        int count=0;
        long long sum=0;
        for(int i=sv-1;i>=0;i--){
            if(i<sv-1&&prime[i]==prime[i+1]){
                continue;
            }
            sum+=prime[i];
            count+=1;
            if(count==3){
                break;
            }
        }
        return sum;
    }
};
