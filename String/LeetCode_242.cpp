/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.

*/

//Time Complexity -- O(n+m)

class Solution {
public:
    bool isAnagram(string s, string t) {

        int n=s.size();
        int m=t.size();
        if(n!=m){
            return false;
        }
        
        //using a hashmap
        unordered_map<char,int>h;
        for(int i=0;i<n;i++){
            h[s[i]]++;
        }

        //check if s and t is a anagram
        for(int i=0;i<m;i++){
            char ch = t[i];
            if(h.count(ch)){
                if(h[ch]==1){
                    h.erase(ch);
                }
                else{
                    h[ch]--;
                }
            }
            else{
                return false;
            }
        }

        //if nothing went wrong
        return true;
    }
};
