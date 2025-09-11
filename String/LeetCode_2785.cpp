/*Given a 0-indexed string s, permute s to get a new string t such that:

All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
Return the resulting string.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.

 */

//Time Complexity -- O(nlogn)

class Solution {
public:
    string sortVowels(string s) {
        set<char>se = {'A','E','I','O','U','a','e','i','o','u'};
        string t;
        int n = s.size();
        string temp;
        for(int i=0;i<n;i++){
            if(se.count(s[i])){
                temp.push_back(s[i]);
            }
        }
        sort(temp.begin(),temp.end());
        int index=0;
        for(int i=0;i<n;i++){
            if(!se.count(s[i])){
                t.push_back(s[i]);
            }
            else{
                t.push_back(temp[index++]);
            }
        }
        return t;
    }
};
