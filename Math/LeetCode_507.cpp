/*A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.

Given an integer n, return true if n is a perfect number, otherwise return false.*/

//Time Complexity -- O(sqrt(num))

class Solution {
public:
    bool checkPerfectNumber(int num) {

        //check for the edge case num==1
        if(num==1){
            return false;
        }
        
        //to store the sum of factors of num
        int sum=1;

        //calculate the factors of x and store their sum
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0){
                sum+=i;
                int pair=num/i;
                sum+=pair;
            }
        }

        //check if the sum equals num
        if(sum==num){
            return true; //true if yes
        }

        return false; //if not equal
    }
};
