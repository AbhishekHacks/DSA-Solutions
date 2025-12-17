/*You are given a string s consisting of lowercase English words, each separated by a single space.

Determine how many vowels appear in the first word. Then, reverse each following word that has the same vowel count. Leave all remaining words unchanged.

Return the resulting string.

Vowels are 'a', 'e', 'i', 'o', and 'u'.*/

//Time Complexity -- O(n)

class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        int n = s.size();
        int count = 0;
        int i;
        for(i=0;i<n;i++){
            if(s[i]==' '){
                break;
            }
            else if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                count++;
            }
        }
        int ptr1 = i+1;
        int count_vow = 0;
        for(int j=i+1;j<n;j++){
            if(s[j]==' '){
                if(count_vow==count){
                    int ptr2 = j-1;
                    while(ptr1<ptr2){
                        swap(s[ptr1],s[ptr2]);
                        ptr1++;
                        ptr2--;
                    }
                }
                ptr1 = j+1;
                count_vow = 0;
            }
            else{
                if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'){
                    count_vow++;
                }
            }
        }
        s.pop_back();
        return s;
    }
};
