/*Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.*/

//Time Complexity -- O(n)

class Solution {
public:
    int firstUniqChar(string s) {
        
        int n = s.size();

        unordered_map<char,int>m;
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }

        for(int i=0;i<n;i++){
            if(m[s[i]]==1){
                return i;
            }
        }

        return -1;
    }
};
