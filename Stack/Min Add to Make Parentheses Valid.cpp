/*You are given a string s consisting only of the characters '(' and ')'. Your task is to determine the minimum number of parentheses (either '(' or ')') that must be inserted at any positions to make the string s a valid parentheses string.

A parentheses string is considered valid if:

Every opening parenthesis '(' has a corresponding closing parenthesis ')'.
Every closing parenthesis ')' has a corresponding opening parenthesis '('.
Parentheses are properly nested.*/

//Time Complexity -- O(n)

class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        stack<char>st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]==')'&&!st.empty()&&st.top()=='('){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return st.size();
    }
};
