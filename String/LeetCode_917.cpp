/*Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.*/

//Time Complexity -- O(n)

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))&&((s[j]>='A'&&s[j]<='Z')||(s[j]>='a'&&s[j]<='z'))){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else{
                if(((s[i]<'A'||s[i]>'Z')&&(s[i]<'a'||s[i]>'z'))&&((s[j]<'A'||s[j]>'Z')&&(s[j]<'a'||s[j]>'z'))){
                    i++;
                    j--;
                }
                else if((s[i]<'A'||s[i]>'Z')&&(s[i]<'a'||s[i]>'z')){
                    i++;
                }
                else{
                    j--;
                }
            }
        }
        return s;
    }
};
