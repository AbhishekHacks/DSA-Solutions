/*Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 */

//Time Complexity -- O(n+k)

class Solution {
public:
    string decodeString(string s) {
        int n  = s.size();
        stack<char>st;
        for(int i=0;i<n;i++){ 
            if(s[i]==']'){
                string temp;
                while(st.top()!='['){ 
                    temp.push_back(st.top());
                    st.pop();
                }
                reverse(temp.begin(),temp.end());
                st.pop();
                string num;
                while(!st.empty()&&st.top()>='0'&&st.top()<='9'){
                    num.push_back(st.top());
                    st.pop();
                }
                reverse(num.begin(),num.end());
                int nums = stoi(num);
                for(int j=1;j<=nums;j++){
                    for(int k=0;k<temp.size();k++){
                        st.push(temp[k]);
                    }
                }
            }
            else{
                st.push(s[i]); 
            }
        }
        string result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
