/*You are given a string word.

Return the maximum number of non-intersecting substrings of word that are at least four characters long and start and end with the same letter.

A substring is a contiguous non-empty sequence of characters within a string.*/

//Time Complexity -- O(n)

class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size();
        int count=0;
        int maximum = INT_MIN;
        unordered_map<char,int>m;
        for(int i=0;i<n;i++){
            if(!m.count(word[i])){
                m[word[i]]=i;
            }
            else{
                int length = i-m[word[i]]+1;
                if(length>=4&&m[word[i]]>maximum){
                    count+=1;
                    maximum = max(maximum,i);
                }
                else if(m[word[i]]<=maximum){
                    m[word[i]]=i;
                }
            }
        }
        return count;
    }
};
