/*Given an encoded string s, decode it by expanding the pattern k[substring], where the substring inside brackets is written k times. k is guaranteed to be a positive integer, and encodedString contains only lowercase english alphabets. Return the final decoded string.

Note: The test cases are generated so that the length of the output string will never exceed 105 .*/

//Time Comnplexity -- O(n)

class Solution {
  public:
    string decodedString(string &s) {
        // code here
        int n = s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]==']'){
                string temp;
                while(st.top()!='['){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                string num;
                while(!st.empty()&&st.top()>='0'&&st.top()<='9'){
                    num.push_back(st.top());
                    st.pop();
                }
                reverse(num.begin(),num.end());
                int number = stoi(num);
                for(int j=1;j<=number;j++){
                    for(int k=temp.size()-1;k>=0;k--){
                        st.push(temp[k]);
                    }
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
