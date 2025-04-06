/*Seven different symbols represent Roman numerals with the following values:

Symbol	Value
I	      1
V	      5
X	      10
L	      50
C	      100
D	      500
M	      1000
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.*/

//Time Complexity -- O(1)

class Solution {
public:
    string intToRoman(int num) {
        
        //output string
        string ans;

        int number_M=num/1000;
        for(int i=1;i<=number_M;i++){
            ans.push_back('M');
        }
        num=num%1000;

        if(num>=900){
            ans.push_back('C');
            ans.push_back('M');
            num=num%100;
        }

        int number_D=num/500;
        for(int i=1;i<=number_D;i++){
            ans.push_back('D');
        }
        num=num%500;

        if(num>=400){
            ans.push_back('C');
            ans.push_back('D');
            num=num%100;
        }

        int number_C=num/100;
        for(int i=1;i<=number_C;i++){
            ans.push_back('C');
        }
        num=num%100;

        if(num>=90){
            ans.push_back('X');
            ans.push_back('C');
            num=num%10;
        }

        int number_L=num/50;
        for(int i=1;i<=number_L;i++){
            ans.push_back('L');
        }
        num=num%50;

        if(num>=40){
            ans.push_back('X');
            ans.push_back('L');
            num=num%10;
        }

        int number_X=num/10;
        for(int i=1;i<=number_X;i++){
            ans.push_back('X');
        }
        num=num%10;

        if(num==9){
            ans.push_back('I');
            ans.push_back('X');
            num=0;
        }

        int number_V=num/5;
        for(int i=1;i<=number_V;i++){
            ans.push_back('V');
        }
        num=num%5;

        if(num==4){
            ans.push_back('I');
            ans.push_back('V');
            num=0;
        }

        int number_I=num/1;
        for(int i=1;i<=number_I;i++){
            ans.push_back('I');
        }

        return ans;
    }
};
