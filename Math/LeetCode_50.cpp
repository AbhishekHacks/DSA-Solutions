/*Implement pow(x, n), which calculates x raised to the power n (i.e., xn).*/

//Time Complexity -- O(logn)

class Solution {
public:
    double myPow(double x, int n) {
        long long p = abs((long long)n);
        double answer = 1;
        while(p>0){
            if(p%2==0){
                x=x*x;
                p=p/2;
            }
            else{
                answer*=x;
                p=p-1;
            }
        }
        if(n<0){
            return 1/answer;
        }
        return answer;
    }
};
