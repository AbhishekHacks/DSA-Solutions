/*Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.*/

//Time Complexity -- O(N)

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int count=0;
        int len = 0;
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                count++;
            }
            else{
                if(count>0){
                    len = count;
                }
                count=0;
            }
        }
        if(count!=0){
            len=count;
        }
        return len;
    }
};
