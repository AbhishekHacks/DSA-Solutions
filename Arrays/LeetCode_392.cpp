/*Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 */

//Time Complexity -- O(n)

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if(n1==0&&n2>=0){
            return true;
        }
        int i=0;
        int j=0;
        while(i<n1&&j<n2){
            if(s[i]==t[j]){
                i++;
                if(i==n1){
                    return true;
                }
            }
            j++;
        }
        return false;
    }
};
