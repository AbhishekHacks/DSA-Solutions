/*Given a positive integer num, return the number of positive integers less than or equal to num whose digit sums are even.

The digit sum of a positive integer is the sum of all its digits.
*/

//Time Complexity -- O(num*log(k))

class Solution {
public:
    int countEven(int num) {
        int count = 0;
        for(int i=1;i<=num;i++){
            int sum = 0;
            int number = i;
            while(number>0){
                int r = number%10;
                sum+=r;
                number/=10;
            }
            if(sum%2==0){
                count++;
            }
        }
        return count;
    }
};
