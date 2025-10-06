/*You are given a string s consisting of '(' and ')', and an integer k.

A string is k-balanced if it is exactly k consecutive '(' followed by k consecutive ')', i.e., '(' * k + ')' * k.

For example, if k = 3, k-balanced is "((()))".

You must repeatedly remove all non-overlapping k-balanced substrings from s, and then join the remaining parts. Continue this process until no k-balanced substring exists.

Return the final string after all possible removals.*/

//Time Complexity -- O(n)

class Solution {
public:
    string removeSubstring(string s, int k) {
        int n = s.size();
        int open_p = 0;
        int close_p = 0;
        stack<char>st;
        stack<int>count_open;
        stack<int>count_close;
        count_open.push(0);
        count_close.push(0);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(close_p==0){
                    open_p++;
                }
                else{
                    open_p=1;
                    close_p=0;
                }
                st.push('(');
                count_open.push(open_p);
                count_close.push(close_p);
            }
            else if(s[i]==')'){
                if(open_p>=k){
                    close_p++;
                }
                else{
                    open_p=0;
                }
                st.push(')');
                count_open.push(open_p);
                count_close.push(close_p);
            }
            if(open_p>=k&&close_p==k){
                for(int count=1;count<=(2*k);count++){
                    st.pop();
                    count_open.pop();
                    count_close.pop();
                }
                open_p=count_open.top();
                close_p=count_close.top();
            }
        }
        string answer;
        while(!st.empty()){
            answer.push_back(st.top());
            st.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};
