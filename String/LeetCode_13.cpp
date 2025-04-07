/*Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.*/

//Time Complexity -- O(n)

class Solution {
public:
    int romanToInt(string s) {

        int n=s.size();
        int ans=0;
        
        int  index=0;
        while(index<n){
            if(s[index]=='M'){
                ans+=1000;
                index+=1;
            }
            else if(s[index]=='C'){
                if(index+1<n&&s[index+1]=='M'){
                    ans+=900;
                    index+=2;
                }
                else if(index+1<n&&s[index+1]=='D'){
                    ans+=400;
                    index+=2;
                }
                else{
                    ans+=100;
                    index+=1;
                }
            }
            else if(s[index]=='D'){
                ans+=500;
                index+=1;
            }
            else if(s[index]=='L'){
                ans+=50;
                index+=1;
            }
            else if(s[index]=='X'){
                if(index+1<n&&s[index+1]=='L'){
                    ans+=40;
                    index+=2;
                }
                else if(index+1<n&&s[index+1]=='C'){
                    ans+=90;
                    index+=2;
                }
                else{
                    ans+=10;
                    index+=1;
                }
            }
            else if(s[index]=='V'){
                ans+=5;
                index+=1;
            }
            else if(s[index]=='I'){
                if(index+1<n&&s[index+1]=='V'){
                    ans+=4;
                    index+=2;
                }
                else if(index+1<n&&s[index+1]=='X'){
                    ans+=9;
                    index+=2;
                }
                else{
                    ans+=1;
                    index+=1;
                }
            }
        }

        return ans;
    }
};
