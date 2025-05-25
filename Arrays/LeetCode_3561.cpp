/*You are given a string s consisting of lowercase English letters.

You must repeatedly perform the following operation while the string s has at least two consecutive characters:

Remove the leftmost pair of adjacent characters in the string that are consecutive in the alphabet, in either order (e.g., 'a' and 'b', or 'b' and 'a').
Shift the remaining characters to the left to fill the gap.
Return the resulting string after no more operations can be performed.

Note: Consider the alphabet as circular, thus 'a' and 'z' are consecutive.*/

//Time Complexity -- O(n)

class Solution {
public:
    string resultingString(string s) {
        stack<char>st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                int curr = s[i];
                int prev = st.top();
                if(abs(curr-prev)==1||abs(curr-prev)==25){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        string answer;
        while(!st.empty()){
            answer.push_back(st.top());
            st.pop();
        }
        int i=0,j=answer.size()-1;
        while(i<j){
            swap(answer[i],answer[j]);
            i++;
            j--;
        }
        return answer;
    }
};
