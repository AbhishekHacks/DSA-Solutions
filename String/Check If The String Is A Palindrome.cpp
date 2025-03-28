/*You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, consider alphabets and numbers only and ignore the symbols and whitespaces.

Note :

String 'S' is NOT case sensitive.
Example :

Let S = “c1 O$d@eeD o1c”.
If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase, we get S = “c1odeedo1c”, which is a palindrome. Hence, the given string is also a palindrome.
*/

//Time Complexity -- O(length of string)

#include <bits/stdc++.h> 
bool checkPalindrome(string s)
{
    // Write your code here.

    int n = s.size();

    //take two pointers
    int i=0;
    int j=n-1;

    //iterate the loop and check if the character at i and j are same ignoring symbols and whitespaces
    while(i<j){

        //ignoring white spaces and symbols
        if(s[i]<'0'||(s[i]>'9'&&s[i]<'A')||(s[i]>'Z'&&s[i]<'a')||s[i]>'z'){
            i++;
        }
        else if(s[j]<'0'||(s[j]>'9'&&s[j]<'A')||(s[j]>'Z'&&s[j]<'a')||s[j]>'z'){
            j--;
        }

        //converting the uppercase into lowercase
        else if(s[i]>='A'&&s[i]<='Z'){
            s[i]=s[i]+32;
        }
        else if(s[j]>='A'&&s[j]<='Z'){
            s[j]=s[j]+32;
        }

        //check if the two characters are not equal removing all the symbols and converting both characters into lowercase
        else if(s[i]!=s[j]){
            return false;
        }

        else{
            i++;
            j--;
        }
    }

    //return true
    return true;
}
