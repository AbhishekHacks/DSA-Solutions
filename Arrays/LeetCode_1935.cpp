/*There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.

Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.*/

//Time Complexity -- O(n)

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        text.push_back(' ');
        int n = text.size();
        unordered_map<char,int>m;
        int l = brokenLetters.size();
        for(int i=0;i<l;i++){
            m[brokenLetters[i]]++;
        }
        int count=0;
        bool wordform = true;
        for(int i=0;i<n;i++){
            if(text[i]==' '){
                if(wordform){
                    count++;
                }
                wordform = true;
            }
            else{
                if(m.count(text[i])){
                    wordform = false;
                }
            }
        }
        return count;
    }
};
