/*Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 */

//Time Complexity -- O(n)

class Solution {
public:
    int maxVowels(string s, int k) {

        int n=s.size();
        int highest=INT_MIN;
        
        //initially calculate the number of vowels in the first substring of length k
        int count=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                count+=1;
            }
        }
        if(highest<count){
            highest=count;
        }

        //now for i>k-1
        for(int i=k;i<n;i++){
            if((s[i-k]=='a'||s[i-k]=='e'||s[i-k]=='i'||s[i-k]=='o'||s[i-k]=='u')&&(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u')){
                count-=1;
            }
            else if((s[i-k]!='a'&&s[i-k]!='e'&&s[i-k]!='i'&&s[i-k]!='o'&&s[i-k]!='u')&&(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')){
                count+=1;
                if(highest<count){
                    highest=count;
                }
            }
        }
        return highest;
    }
};
