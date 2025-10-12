/*You are given a string s consisting of lowercase English letters.

A substring of s is called balanced if all distinct characters in the substring appear the same number of times.

Return the length of the longest balanced substring of s.*/

//Time Complexity -- O(n*n*26)

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maximum = INT_MIN;
        for(int i=0;i<n;i++){
            unordered_map<char,int>m;
            for(int j=i;j<n;j++){
                m[s[j]]++;
                auto it = m.begin();
                int freq = it->second;
                bool same = true;
                for(auto i:m){
                    if(i.second!=freq){
                        same=false;
                        break;
                    }
                }
                if(same){
                    maximum = max(maximum,(j-i+1));
                }
            }
        }
        return maximum;
    }
};
