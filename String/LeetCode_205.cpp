/*Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.*/

//Time Complexity -- O(n)

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int n=s.size();
        
        //logic --> lets take a hashmap and than first store the key as string s character and valus as string t character and check when another such key comes do the previous such key had the same value as now , if not return false if yes continue.

        unordered_map<char,char>m;
        unordered_map<char,int>temp;

        for(int i=0;i<n;i++){

            //if key is present
            if(m.count(s[i])){

                //lets check the existing key and current key
                char existing = m[s[i]];
                char current = t[i];
                if(existing!=current){
                    return false;
                }
            }
            else{
                if(temp.count(t[i])){
                    return false;
                }
                m[s[i]]=t[i];
                temp[t[i]]=1;
            }
        }

        //if every thing is checked and no false , return true
        return true;
    }
};
