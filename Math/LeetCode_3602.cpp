/*You are given an integer n.

Return the concatenation of the hexadecimal representation of n2 and the hexatrigesimal representation of n3.

A hexadecimal number is defined as a base-16 numeral system that uses the digits 0 – 9 and the uppercase letters A - F to represent values from 0 to 15.

A hexatrigesimal number is defined as a base-36 numeral system that uses the digits 0 – 9 and the uppercase letters A - Z to represent values from 0 to 35.*/

//Time Complexity -- O(log(n^2)+log(n^3))

class Solution {
public:
    string concatHex36(int n) {
        string hexadecimal;
        string hexatrigecimal;
        int num1 = pow(n,2);
        int num2 = pow(n,3);
        while(num1>0){
            int r = num1%16;
            char ch;
            if(r>=10){
                ch = 55+r;
            }
            else{
                ch = r + '0';
            }
            hexadecimal.push_back(ch);
            num1/=16;
        }
        while(num2>0){
            int r = num2%36;
            char ch;
            if(r>=10){
                ch = 55+r;
            }
            else{
                ch = r + '0';
            }
            hexatrigecimal.push_back(ch);
            num2/=36;
        }
        reverse(hexadecimal.begin(),hexadecimal.end());
        reverse(hexatrigecimal.begin(),hexatrigecimal.end());
        hexadecimal.append(hexatrigecimal);
        return hexadecimal;
    }
};
