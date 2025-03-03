/*Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as sqrt.*/

//Time Complexity -- O(logn)

class Solution {
public:
    bool isPerfectSquare(int num) {
        int start=1;
        int end=num;
        while(start<=end){
            int mid=start+(end-start)/2;
            long long sq = (long long)mid*mid;
            if(sq==num){
                return true;
            }
            else if(sq>num){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return false;
    }
};
