/*You are given a string s consisting only of lowercase English letters.

You can perform the following operation any number of times (including zero):

Choose any character c in the string and replace every occurrence of c with the next lowercase letter in the English alphabet.

Return the minimum number of operations required to transform s into a string consisting of only 'a' characters.

Note: Consider the alphabet as circular, thus 'a' comes after 'z'.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        sort(s.begin(),s.end());
        int tot_op = 0;
        for(int i=1;i<n;i++){
            if(s[i-1]!='a'){
                tot_op+=(s[i]-s[i-1]);
            }
        }
        if(s[n-1]!='a'){
            tot_op+=(123-s[n-1]);
        }
        return tot_op;
    }
};
