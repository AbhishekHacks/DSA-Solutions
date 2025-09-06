/*You are given a string sentence that consist of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:

If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append "ma" to the end of the word.
For example, the word "apple" becomes "applema".
If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end, and so on.
Return the final sentence representing the conversion from sentence to Goat Latin.*/

//Time Complexity -- O(n)

class Solution {
public:
    string toGoatLatin(string sentence) {
        sentence.push_back(' ');
        int n = sentence.size();
        string ans;
        string temp;
        set<char>s_vowel = {'A','E','I','O','U','a','e','i','o','u'};
        int index = 1;
        for(int i=0;i<n;i++){
            if(sentence[i]==' '){
                char ch = temp[0];
                if(s_vowel.count(ch)){
                    temp.append("ma");
                }
                else{
                    temp.erase(temp.begin(),temp.begin()+1);
                    temp.push_back(ch);
                    temp.append("ma");
                }
                for(int i=1;i<=index;i++){
                    temp.push_back('a');
                }
                ans.append(temp);
                if(i!=n-1){
                    ans.push_back(' ');
                }
                index++;
                temp.clear();
            }
            else{
                temp.push_back(sentence[i]);
            }
        }
        return ans;
    }
};
