/*You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

 */

//Time Complexity -- O(n)

class Solution {
public:

    int maximumscore(string s, int x, int y, char ch1, char ch2){
        int n = s.size();
        stack<char>st;
        int count = 0;
        int i = 0;
        while(i<n){
            if(st.empty()||s[i]!=ch2){
                st.push(s[i]);
            }
            else if(s[i]==ch2){
                if(st.top()==ch1){
                    count+=x;
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
            i++;
        }
        string s_new;
        while(!st.empty()){
            s_new.push_back(st.top());
            st.pop();
        }
        reverse(s_new.begin(),s_new.end());
        int n_new = s_new.size();
        int j = 0;
        while(j<n_new){
            if(st.empty()||s_new[j]!=ch1){
                st.push(s_new[j]);
            }
            else if(s_new[j]==ch1){
                if(st.top()==ch2){
                    count+=y;
                    st.pop();
                }
                else{
                    st.push(s_new[j]);
                }
            }
            j++;
        }
        return count;
    }

    int maximumGain(string s, int x, int y) {
        if(x>=y){
            return maximumscore(s,x,y,'a','b');
        }
        return maximumscore(s,y,x,'b','a');
    }
};
