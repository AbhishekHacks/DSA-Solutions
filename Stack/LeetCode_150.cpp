/*You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
*/

//Time Complexity -- O(n)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n = tokens.size();
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int res = num1+num2;
                st.push(res);
            }
            else if(tokens[i]=="-"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int res = num2-num1;
                st.push(res);
            }
            else if(tokens[i]=="*"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int res = num1*num2;
                st.push(res);
            }
            else if(tokens[i]=="/"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int res = num2/num1;
                st.push(res);
            }
            else{
                int num = stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};
