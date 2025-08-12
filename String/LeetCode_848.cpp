/*You are given a string s of lowercase English letters and an integer array shifts of the same length.

Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').

For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.

Return the final string after all such shifts to s are applied.*/

//Time Complexity -- O(n)

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        string ans;
        int n = shifts.size();
        unordered_map<int,char>m;
        vector<long long>suffix(n,0);
        suffix[n-1] = shifts[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i] = shifts[i]+suffix[i+1];
        }
        for(int i=0;i<n;i++){
            char ch = ((s[i]-97+suffix[i])%26)+97;
            ans.push_back(ch);
        }
        return ans;
    }
};
