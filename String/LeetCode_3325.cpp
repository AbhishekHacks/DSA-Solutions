/*Given a string s and an integer k, return the total number of substrings of s where at least one character appears at least k times.*/

//Time Complexity -- O(n^2)

class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        int count=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>m;
            for(int j=i;j<n;j++){
                m[s[j]]++;
                if(m[s[j]]>=k){
                    count+=(n-j);
                    break;
                }
            }
        }
        return count;
    }
};
