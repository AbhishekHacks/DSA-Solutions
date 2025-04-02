/*Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.*/

//Time Complexity -- O(N)

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n = s.size();

        //logic --> start iterating from the end and when you encounter spaces just igmore them but as soon as you encounter a character increase the count variable and when at any point you encounter a space just break the loop and return the length(count)
        bool space = false;
        bool character = false;
        int count=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==' '&&character==false){
                continue;
            }
            else if(s[i]!=' '){
                count++;
                character=true;
            }
            else if(s[i]==' '&&character==true){
                break;
            }
        }

        //return the length
        return count;
    }
};
