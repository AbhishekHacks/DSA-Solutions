/*Given an integer num, return a string of its base 7 representation.

 

Example 1:

Input: num = 100
Output: "202"
Example 2:

Input: num = -7
Output: "-10"
*/

//Time Complexity -- O(log(num))

class Solution {
public:
    string convertToBase7(int num) {
        if(num==0){
            return "0";
        }
        string str;
        int n = num;
        num=abs(num);
        while(num>0){
            int rem = num%7;
            char ch = rem+'0';
            str.push_back(ch);
            num/=7;
        }
        if(n<0){
            str.push_back('-');
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
