/*You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.
 */

//Time Complexity -- O(n)

class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string output;
        while(!st.empty()){
            output.push_back(st.top());
            st.pop();
        }
        reverse(output.begin(),output.end());
        return output;
    }
};
