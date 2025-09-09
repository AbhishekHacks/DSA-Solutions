/*Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

Given a balanced string s, split it into some number of substrings such that:

Each substring is balanced.
Return the maximum number of balanced strings you can obtain.*/

//Time Complexity -- O(n)

class Solution {
public:
    int balancedStringSplit(string s) {
        int n=s.size();
        int L_count=0;
        int R_count=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                L_count++;
            }
            else{
                R_count++;
            }
            if(L_count==R_count){
                count++;
                L_count=0;
                R_count=0;
            }
        }
        return count;
    }
};
