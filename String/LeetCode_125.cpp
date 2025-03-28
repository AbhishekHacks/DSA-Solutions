/*A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.*/

//Time Complexity -- O(length of string)

class Solution {
public:
    bool isPalindrome(string s) {
        
        int n = s.size();

        //taking two pointers 
        int i=0;
        int j=n-1;

        //iterate the loop and remove all the non-alphanumeric characters and covert uppercase into lowercase and than at the last check if the characters at i and j are equal
        while(i<j){

            //non-alphanumeric
            if(s[i]<'0'||(s[i]>'9'&&s[i]<'A')||(s[i]>'Z'&&s[i]<'a')||s[i]>'z'){
                i++;
            }
            else if(s[j]<'0'||(s[j]>'9'&&s[j]<'A')||(s[j]>'Z'&&s[j]<'a')||s[j]>'z'){
                j--;
            }

            //uppercase into lowercase
            else if(s[i]>='A'&&s[i]<='Z'){
                s[i]=s[i]+32;
            }
            else if(s[j]>='A'&&s[j]<='Z'){
                s[j]=s[j]+32;
            }

            //compare
            else if(s[i]!=s[j]){
                return false;
            }

            //increment and decrement
            else{
                i++;
                j--;
            }
        }

        //return true
        return true;
    }
};
