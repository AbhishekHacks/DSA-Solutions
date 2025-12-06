/*You are given an integer num.

A number num is called a Complete Prime Number if every prefix and every suffix of num is prime.

Return true if num is a Complete Prime Number, otherwise return false.

Note:

A prefix of a number is formed by the first k digits of the number.
A suffix of a number is formed by the last k digits of the number.
A prime number is a natural number greater than 1 with only two factors, 1 and itself.
Single-digit numbers are considered Complete Prime Numbers only if they are prime.*/

//Time Complexity -- O(k*sqrt(num))

class Solution {
public:

    bool isPrime(int number){
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

    bool completePrime(int num) {
        //prefix
        int temp = num;
        int count_0 = 0;
        while(temp>0){
            count_0++;
            temp/=10;
        }
        count_0--;
        while(count_0>=0){
            int t = num/pow(10,count_0);
            if(!isPrime(t)){
                return false;
            }
            count_0--;
        }
        //suffix
        int n = 0;
        int count = 0;
        while(num>0){
            int r = num%10;
            n = (r*pow(10,count))+n;
            if(!isPrime(n)){
                return false;
            }
            count++;
            num/=10;
        }
        return true;
    }
};
