/*Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.*/

class Solution {
public:
    int mySqrt(int x) {
        int start=0;
        int end=x;
        int ans=0;
        while(start<=end){
            long long mid = start+(end-start)/2;
            if(mid*mid==x){
                return mid;
            }
            else if(mid*mid>x){
                end=mid-1;
            }
            else{
                ans=mid;
                start = mid+1;
            }
        }
        return ans;
    }
};
