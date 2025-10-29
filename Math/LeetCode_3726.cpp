/*You are given a positive integer n.

Return the integer obtained by removing all zeros from the decimal representation of n.

*/

//Time Complexity -- O(log(n))

class Solution {
public:
    long long removeZeros(long long n) {
        long long temp=0;
        while(n>0){
            int r = n%10;
            if(r!=0){
                temp=(temp*10)+r;
            }
            n/=10;
        }
        long long ans=0;
        while(temp>0){
            int r = temp%10;
            ans=(ans*10)+r;
            temp/=10;
        }
        return ans;
    }
};
