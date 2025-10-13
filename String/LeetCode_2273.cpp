/*You are given a 0-indexed string array words, where words[i] consists of lowercase English letters.

In one operation, select any index i such that 0 < i < words.length and words[i - 1] and words[i] are anagrams, and delete words[i] from words. Keep performing this operation as long as you can select an index that satisfies the conditions.

Return words after performing all operations. It can be shown that selecting the indices for each operation in any arbitrary order will lead to the same result.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase using all the original letters exactly once. For example, "dacb" is an anagram of "abdc".*/

//Time Complexity -- O(n*mlogm)

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string>ans;
        ans.push_back(words[0]);
        for(int i=1;i<n;i++){
            string prev = words[i-1];
            string curr = words[i];
            sort(prev.begin(),prev.end());
            sort(curr.begin(),curr.end());
            if(curr!=prev){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
