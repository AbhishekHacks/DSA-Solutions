/*Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.*/

//Time Complexity -- O(n)

class Solution {
public:
    string reverseVowels(string s) {
        
        int n = s.size();
        unordered_map<char,int>m;
        m['A']=1;m['E']=1;m['I']=1;m['O']=1;m['U']=1;
        m['a']=1;m['e']=1;m['i']=1;m['o']=1;m['u']=1;
        
        int i=0;
        int j=n-1;
        while(i<j){
            if(m.count(s[i])&&m.count(s[j])){
                char temp = s[i];
                s[i]=s[j];
                s[j]=temp;
                i++;
                j--;
            }
            else if(m.count(s[i])){
                j--;
            }
            else if(m.count(s[j])){
                i++;
            }
            else{
                i++;
                j--;
            }
        }

        return s;
    }
};
