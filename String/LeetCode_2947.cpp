/*You are given a string s and a positive integer k.

Let vowels and consonants be the number of vowels and consonants in a string.

A string is beautiful if:

vowels == consonants.
(vowels * consonants) % k == 0, in other terms the multiplication of vowels and consonants is divisible by k.
Return the number of non-empty beautiful substrings in the given string s.

A substring is a contiguous sequence of characters in a string.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

Consonant letters in English are every letter except vowels.*/

//Time Complexity -- O(n^2)

class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        int count=0;
        for(int i=0;i<n;i++){
            int vowel=0;
            int consonant=0;
            for(int j=i;j<n;j++){
                if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'){
                    vowel++;
                }
                else{
                    consonant++;
                }
                if((vowel==consonant)&&((vowel*consonant)%k==0)){
                    count++;
                }
            }
        }
        return count;
    }
};
