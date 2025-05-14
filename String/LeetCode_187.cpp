/*The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

*/

//Time Complexity -- O(N)

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string>output;
        unordered_map<string,int>m;
        for(int i=0;i<=n-10;i++){
            string str;
            for(int j=0;j<10;j++){
                str.push_back(s[i+j]);
            }
            m[str]++;   
        }
        for(auto i:m){
            if(i.second>1){
                output.push_back(i.first);
            }
        }
        return output;
    }
};
