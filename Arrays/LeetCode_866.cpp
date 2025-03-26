/*Given an integer n, return the smallest prime palindrome greater than or equal to n.

An integer is prime if it has exactly two divisors: 1 and itself. Note that 1 is not a prime number.

For example, 2, 3, 5, 7, 11, and 13 are all primes.
An integer is a palindrome if it reads the same from left to right as it does from right to left.

For example, 101 and 12321 are palindromes.
The test cases are generated so that the answer always exists and is in the range [2, 2 * 108].

*/

//Time Complexity -- O(Nlog(N))

class Solution {
public:

    //function to check palindrome number
    bool isPalindrome(int number){
        int rev=0;
        int temp=number;
        while(temp>0){
            int r=temp%10;
            rev=(rev*10)+r;
            temp=temp/10;
        }
        if(number==rev){
            return true;
        }
        return false;
    }

    //function to check if a number is prime
    bool isPrime(int number){
        if(number==1){
            return false;
        }
        int limit=sqrt(number);
        for(int i=2;i<=limit;i++){
            if(number%i==0){
                return false;
            }
        }
        return true;
    }

    int primePalindrome(int n) {
        
        //iterate to check the smallest prime palindrome
        int answer=0;

        //edge case
        if(n==1){
            return 2;
        }

        if(n%2==0&&n>2){
            n=n+1;
        }
        for(int i=n;i<=200000001;i+=2){
            if(isPalindrome(i)&&isPrime(i)){
                answer=i;
                break;
            }
        }
        
        //return the smallest prime palindrome
        return answer;
    }
};
