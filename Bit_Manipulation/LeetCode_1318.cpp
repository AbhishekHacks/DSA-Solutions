/*Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.

*/

//Time Complexity -- O(1)

class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int flip=0;

        while(a>0 || b>0 || c>0){
            int r = (c&1);
            int d1 = (a&1);
            int d2 = (b&1);
            if(r==0){
                if(d1!=0 && d2!=0){
                    flip+=2;
                }
                else if(d1!=0 || d2!=0){
                    flip+=1;
                }
            }
            else{
                if(d1==0&&d2==0){
                    flip+=1;
                }
            }

            a=a>>1;
            b=b>>1;
            c=c>>1;
        }

        return flip;
    }
};
