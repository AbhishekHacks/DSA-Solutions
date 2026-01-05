/*You are given a string s and an integer k.

Reverse the first k characters of s and return the resulting string.*/

//Time Complexity -- O(n)

class Solution {
public:
    string reversePrefix(string s, int k) {
        int i = 0,j = k-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
};
