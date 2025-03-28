/*Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.*/

//Time Complexity -- O(N)

class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        while(s.size()>0&&s.find(part)!=-1){
            s.erase(s.find(part),part.size());
        }

        //return new string with removed substrings
        return s;
    }
};
