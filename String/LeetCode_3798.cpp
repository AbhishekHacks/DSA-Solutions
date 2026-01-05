/*You are given a string s consisting only of the characters '1' and '2'.

You may delete any number of characters from s without changing the order of the remaining characters.

Return the largest possible resultant string that represents an even integer. If there is no such string, return the empty string "".*/

//Time Complexity --O(n)

class Solution {
public:
    string largestEven(string s) {
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                s.pop_back();
            }
            else{
                break;
            }
        }
        return s;
    }
};
