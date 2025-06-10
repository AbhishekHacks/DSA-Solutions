/*You are given a string s consisting of lowercase English letters.

Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:

a1 has an odd frequency in the string.
a2 has an even frequency in the string.
Return this maximum difference.

 */

//Time Complexity -- O(n)

class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();
        unordered_map<char,int>m;
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        int maximum = INT_MIN;
        int minimum = INT_MAX;
        for(auto i:m){
            if(i.second%2!=0){
                if(maximum<i.second){
                    maximum=i.second;
                }
            }
            else{
                if(minimum>i.second){
                    minimum=i.second;
                }
            }
        }
        return maximum-minimum;
    }
};
