/*You are given a string s consisting of lowercase English letters and the special characters: *, #, and %.

Build a new string result by processing s according to the following rules from left to right:

If the letter is a lowercase English letter append it to result.
A '*' removes the last character from result, if it exists.
A '#' duplicates the current result and appends it to itself.
A '%' reverses the current result.
Return the final string result after processing all characters in s.*/

//Time Complexity -- O(n^2)

class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string result;
        for(int i=0;i<n;i++){
            if(s[i]>='a'&&s[i]<='z'){
                result.push_back(s[i]);
            }
            else if(s[i]=='*'){
                if(result.size()>0){
                    result.pop_back();
                }
            }
            else if(s[i]=='#'){
                string temp = result;
                result.append(temp);
            }
            else if(s[i]=='%'){
                reverse(result.begin(),result.end());
            }
        }
        return result;
    }
};
