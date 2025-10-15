/*You are given a string s consisting of lowercase English letters.

The score of a string is the sum of the positions of its characters in the alphabet, where 'a' = 1, 'b' = 2, ..., 'z' = 26.

Determine whether there exists an index i such that the string can be split into two non-empty substrings s[0..i] and s[(i + 1)..(n - 1)] that have equal scores.

Return true if such a split exists, otherwise return false.*/

//Time Complexity -- O(n)

class Solution {
public:
    bool scoreBalance(string s) {
        int leftsum = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            leftsum+=(s[i]-'a'+1);
        }
        int rightsum=0;
        for(int i=n-1;i>=1;i--){
            rightsum+=(s[i]-'a'+1);
            if((leftsum-rightsum)==rightsum){
                return true;
            }
        }
        return false;
    }
};
