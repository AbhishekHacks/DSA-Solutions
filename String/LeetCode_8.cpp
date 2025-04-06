/*Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.*/

//Time Complexity - O(N)

class Solution {
public:
    int myAtoi(string s) {
        
        //logic -- first determine if the first character in the string is a non-digit , if yes than the result is 0
        
        int n = s.size();
        bool digit = false;
        bool sign = false;
        bool leadingspace = false;
        bool character = false;
        char plusorminus='+';
        int indexofdigit=-1;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(sign==true){
                    return 0;
                }
                leadingspace=true;
            }
            else if(s[i]=='+'||s[i]=='-'){
                if(sign==true){
                    return 0;
                }
                plusorminus=s[i];
                sign=true;
            }
            else if(s[i]>='0'&&s[i]<='9'){
                indexofdigit=i;
                break;
            }
            else{
                return 0;
            }
        }

        //lets check if there is no digit in the string
        if(indexofdigit==-1){
            return 0;
        }
        
        //now we are guranteed to have an integer greater than equal to 0
        //we know that the first digit appeared in indexofdigit th index
        //run a loop from that point till the point we encounter anything other than character
        string str;
        for(int i=indexofdigit;i<n;i++){
            if(s[i]<'0'||s[i]>'9'){
                break;
            }
            str.push_back(s[i]);
        }

        //now we have our answer stored in a string str
        //take help of a long long data type to keep the integer in bounds
        int m = str.size();
        long long temp=0;
        for(int i=0;i<m;i++){
            int r = str[i]-'0';
            temp = (temp*10)+r;
            if(plusorminus=='-'){
                if(temp>2147483648){
                    return -2147483648;
                }
            }
            else{
                if(temp>2147483647){
                    return 2147483647;
                }
            }
        }

        //finally if the digit is already in bounds
        if(plusorminus=='-'){
            temp=(-1)*temp;
        }
        return temp;
    }
};
