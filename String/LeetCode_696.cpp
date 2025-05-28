/*Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

*/

//Time Complexity -- O(n)

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        vector<int>freq;
        int count=0;
        char prev=s[0];
        for(int i=0;i<n;i++){
            char curr=s[i];
            if(prev==curr){
                count+=1;
            }
            else{
                freq.push_back(count);
                i--;
                count=0;
            }
            prev=curr;
        }
        freq.push_back(count);
        if(freq.size()<2){
            return 0;
        }
        int i=0;
        int j=1;
        int result=0;
        while(j<freq.size()){
            result+=min(freq[i],freq[j]);
            i++;
            j++;
        }
        return result;
    }
};
