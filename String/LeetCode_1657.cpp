/*Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

*/

//Time Complexity -- O(n)

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if(n1!=n2){
            return false;
        }
        unordered_map<char,int>m1;
        for(int i=0;i<n1;i++){
            m1[word1[i]]++;
        }
        unordered_map<char,int>m2;
        for(int i=0;i<n2;i++){
            m2[word2[i]]++;
        }
        //base case
        for(auto i:m1){
            if(m2.count(i.first)==0){
                return false;
            }
        }
        unordered_map<int,int>m3;
        unordered_map<int,int>m4;
        for(auto i:m1){
            m3[i.second]++;
        }
        for(auto i:m2){
            m4[i.second]++;
        }
        for(auto i:m3){
            if(m4.count(i.first)){
                if(i.second!=m4[i.first]){
                    return false;
                }
            }
            else{
                return false;
            }
        }

        return true;
    }
};
