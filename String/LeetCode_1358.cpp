/*Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

*/

//Time Complexity -- O(N)

class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> m;
        int n=s.length();
        int starting=0;
        int i=-1;
        int ans=0;
        while(i<n){
            if(m['a']>=1 && m['b']>=1 && m['c']>=1){
                ans+=(n-i);
                m[s[starting]]--;
                starting++;
            }
            else{
                i++;
                m[s[i]]++;
            }
        }
        return ans;
    }
};
