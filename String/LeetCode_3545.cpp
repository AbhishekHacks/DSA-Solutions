/*You are given a string s consisting of lowercase English letters, and an integer k.

Your task is to delete some (possibly none) of the characters in the string so that the number of distinct characters in the resulting string is at most k.

Return the minimum number of deletions required to achieve this.*/

//Time Complexity -- O(n^2)

class Solution {
public:
    int minDeletion(string s, int k) {
        int n = s.size();
        unordered_map<char,int>m;
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        int remove = m.size() - k;
        int output=0;
        for(int i=1;i<=remove;i++){
            int minimum = INT_MAX;
            char ch;
            for(auto i:m){
                if(minimum>i.second){
                    minimum = i.second;
                    ch = i.first;
                }
            }
            m.erase(ch);
            output+=minimum;
        }

        return output;
    }
};
