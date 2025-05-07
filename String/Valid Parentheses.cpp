/*You're given a string 'S' consisting of "{", "}", "(", ")", "[" and "]" .



Return true if the given string 'S' is balanced, else return false.



For example:
'S' = "{}()".

There is always an opening brace before a closing brace i.e. '{' before '}', '(' before ').
So the 'S' is Balanced.*/

//Time Complexity -- O(N)

#include<bits/stdc++.h>
bool isValidParenthesis(string s)
{
    // Write your code here.

    stack<char>st;
    int n = s.size();

    for(int i=0;i<n;i++){
        char ch = s[i];
        if(st.empty()){
            st.push(ch);
        }
        else if(s[i]=='}'){
            if(st.top()=='{'){
                st.pop();
            }
            else{
                return false;
            }
        }
        else if(s[i]==')'){
            if(st.top()=='('){
                st.pop();
            }
            else{
                return false;
            }
        }
        else if(s[i]==']'){
            if(st.top()=='['){
                st.pop();
            }
            else{
                return false;
            }
        }
        else{
            st.push(ch);
        }
    }
    if(st.empty()){
        return true;
    }
    return false;
}
