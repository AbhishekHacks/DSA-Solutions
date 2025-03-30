/*You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 */

//Time Complexity -- O(N+M)

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int n=word1.size();
        int m=word2.size();

        //output string
        string result;

        //traverse the two string simultaneously using i and j
        int i=0;
        int j=0;
        while(i<n&&j<m){
            
            //push the first charcter of word1 and than of word 2
            result.push_back(word1[i]);
            result.push_back(word2[j]);
            i++;
            j++;
        }

        while(i<n){

            //if i did not reach n fill all the characters of word1
            result.push_back(word1[i]);
            i++;
        }

        //similarly for word2
        while(j<m){
            result.push_back(word2[j]);
            j++;
        }

        //return the output string
        return result;
    }
};
