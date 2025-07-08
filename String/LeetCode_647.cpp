/*Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 */

//Time Complexity -- O(n^2)

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = n;
        //odd palindromes
        for(int i=1;i<n-1;i++){
            int prev = i-1;
            int next = i+1;
            while(prev>=0&&next<=n-1){
                if(s[prev]==s[next]){
                    count++;
                    prev--;
                    next++;
                }
                else{
                    break;
                }
            }
        }
        //even palindromes
        int i=0;
        int j=1;
        while(j<n){
            if(s[i]==s[j]){
                count++;
                int prev = i-1;
                int next = j+1;
                while(prev>=0&&next<=n-1){
                    if(s[prev]==s[next]){
                        count++;
                        prev--;
                        next++;
                    }
                    else{
                        break;
                    }
                }
            }
            i++;
            j++;
        }
        return count;
    }
};
