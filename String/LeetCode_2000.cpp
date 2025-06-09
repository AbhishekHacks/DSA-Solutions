/*Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
Return the resulting string.

 */

//Time Complexity --O(n)

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = word.find(ch);
        if(index==-1){
            return word;
        }
        int i=0,j=index;
        while(i<j){
            swap(word[i],word[j]);
            i++;
            j--;
        }
        return word;
    }
};
