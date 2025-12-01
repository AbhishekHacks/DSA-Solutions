/*You are given a string s consisting of lowercase English letters.

Return an integer denoting the maximum number of substrings you can split s into such that each substring starts with a distinct character (i.e., no two substrings start with the same character).*/

//Time Complexity -- O(n)

class Solution {
public:
    int maxDistinct(string s) {
        int n = s.size();
        int count = 0;
        unordered_map<char,int>m;
        int i=0,j=0;
        while(j<n-1){
            if(s[j]!=s[j+1]&&!m.count(s[j+1])&&s[j+1]!=s[i]){
                count++;
                m[s[i]]++;
                i=j+1;
            }
            j++;
        }
        return (count+1);
    }
};
