/*A word is considered valid if:

It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.

Return true if word is valid, otherwise, return false.

Notes:

'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
A consonant is an English letter that is not a vowel.*/

//Time Complexity -- O(N)

class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3){
            return false;
        }
        set<char>s = {'A','E','I','O','U','a','e','i','o','u'};
        int v = 0;
        int d = 0;
        for(int i=0;i<word.size();i++){
            if(isalnum(word[i])){
                if(s.count(word[i])){
                    v+=1;
                }
                else if(isdigit(word[i])){
                    d+=1;
                }
            }
            else{
                return false;
            }
        }
        if(v==0||(v+d)==word.size()){
            return false;
        }
        return true;
    }
};
