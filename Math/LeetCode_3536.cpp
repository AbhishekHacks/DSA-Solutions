/*You are given a positive integer n.

Return the maximum product of any two digits in n.

Note: You may use the same digit twice if it appears more than once in n.*/

//Time Complexity -- O(logn)

class Solution {
public:
    int maxProduct(int n) {
        int first=0;
        int second=0;
        while(n>0){
            int r = n%10;
            if(first<r){
                second = first;
                first=r;
            }
            else{
                second = max(second,r);
            }
            n=n/10;
        }
        return first*second;
    }
};
