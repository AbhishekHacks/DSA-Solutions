/*Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].*/

class Solution {
public:
    int findNthDigit(int n) {
        int start=0;
        long long sum = 0;
        int count=1;
        int range=0;
        while(n>sum){
            range = sum;
            sum = sum + 9*pow(10,start)*count;
            start++;
            count++;
        }
        count-=1;
        int leftdigits = n - range;
        int div = leftdigits/count;
        int rem = leftdigits%count;
        int power=pow(10,count-1);
        int number = power+div-1;
        int digit;
        if(rem==0){
            return number%10;
        }
        number+=1;
        while(rem>0){
            digit = number/(int)pow(10,count-1);
            number = number%(int)pow(10,count-1);
            count--;
            rem--;
        }
        return digit;
    }
};
