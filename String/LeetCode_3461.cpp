/*You are given a string s consisting of digits. Perform the following operation repeatedly until the string has exactly two digits:

For each pair of consecutive digits in s, starting from the first digit, calculate a new digit as the sum of the two digits modulo 10.
Replace s with the sequence of newly calculated digits, maintaining the order in which they are computed.
Return true if the final two digits in s are the same; otherwise, return false.*/

//Time Complexity -- O(n^2)

class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>2){
            string str;
            for(int i=0;i<s.size()-1;i++){
                int digit1 = s[i]-'0';
                int digit2 = s[i+1]-'0';
                int new_digit = (digit1+digit2)%10;
                str.push_back(new_digit+'0');
            }
            s=str;
        }
        if(s[0]==s[1]){
            return true;
        }
        return false;
    }
};
