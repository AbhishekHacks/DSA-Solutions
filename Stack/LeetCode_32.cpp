/*Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

*/

//Time Complexity -- O(n)

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int>st;
        st.push(-1);
        int longest = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int length = i - st.top();
                    longest = max(longest,length);
                }
            }
        }
        return longest;
    }
};
