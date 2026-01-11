/*You are given a string s consisting only of lowercase English letters.

A prefix of s is called a residue if the number of distinct characters in the prefix is equal to len(prefix) % 3.

Return the count of residue prefixes in s.

A prefix of a string is a non-empty substring that starts from the beginning of the string and extends to any point within it.*/

//Time Complexity -- O(n)

class Solution {
public:
    int residuePrefixes(string s) {
        int n = s.size();
        unordered_map<char,int>m;
        int count = 0;
        for(int i=0;i<n;i++){
            m[s[i]]++;
            if(m.size()==((i+1)%3)){
                count++;
            }
        }
        return count;
    }
};
