/*Given a non-negative integer num, return true if num can be expressed as the sum of any non-negative integer and its reverse, or false otherwise.*/

class Solution {
public:
    
    int reversenum(int n){
        int reverse=0;
        while(n>0){
            int r=n%10;
            reverse=(reverse*10)+r;
            n=n/10;
        }
        return reverse;
    }
    
    bool sumOfNumberAndReverse(int num) {
        //Brute Force
        for(int i=0;i<=num;i++){
            if(i+reversenum(i)==num){
                return 1;
            }
        }
        return 0;
    }
};
