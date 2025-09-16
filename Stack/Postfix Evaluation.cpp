/*You are given an array of strings arr[] that represents a valid arithmetic expression written in Reverse Polish Notation (Postfix Notation). Your task is to evaluate the expression and return an integer representing its value.

Note: A postfix expression is of the form operand1 operand2 operator (e.g., "a b +"). 
And the division operation between two integers always computes the floor value, i.e floor(5 / 3) = 1 and floor(-5 / 3) = -2.
It is guaranteed that the result of the expression and all intermediate calculations will fit in a 32-bit signed integer.

*/

//Time Complexity -- O(n)

class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<string>s;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]=="+"){
                int first = stoi(s.top());
                s.pop();
                int second = stoi(s.top());
                s.pop();
                int result = second + first;
                s.push(to_string(result));
            }
            else if(arr[i]=="-"){
                int first = stoi(s.top());
                s.pop();
                int second = stoi(s.top());
                s.pop();
                int result = second - first;
                s.push(to_string(result));
            }
            else if(arr[i]=="*"){
                int first = stoi(s.top());
                s.pop();
                int second = stoi(s.top());
                s.pop();
                int result = second * first;
                s.push(to_string(result));
            }
            else if(arr[i]=="/"){
                int first = stoi(s.top());
                s.pop();
                int second = stoi(s.top());
                s.pop();
                int result = floor((double)second / first);
                s.push(to_string(result));
            }
            else if(arr[i]=="^"){
                int first = stoi(s.top());
                s.pop();
                int second = stoi(s.top());
                s.pop();
                int result = pow(second,first);
                s.push(to_string(result));
            }
            else{
                s.push(arr[i]);
            }
        }
        return stoi(s.top());
    }
};
