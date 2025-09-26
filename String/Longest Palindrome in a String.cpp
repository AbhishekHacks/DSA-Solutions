/*Given a string s, your task is to find the longest palindromic substring within s.

A substring is a contiguous sequence of characters within a string, defined as s[i...j] where 0 ≤ i ≤ j < len(s).

A palindrome is a string that reads the same forward and backward. More formally, s is a palindrome if reverse(s) == s.

Note: If there are multiple palindromic substrings with the same length, return the first occurrence of the longest palindromic substring from left to right.*/

//Time Complexity -- O(n^2)

class Solution {
  public:
  
    string findpalindrome(string &s,int n,int maximum){
        int i=0,j=maximum-1;
        while(j<n){
            int ptr1=i,ptr2=j;
            bool palin=true;
            while(ptr1<ptr2){
                if(s[ptr1]!=s[ptr2]){
                    palin=false;
                    break;
                }
                ptr1++;
                ptr2--;
            }
            if(palin){
                break;
            }
            i++;
            j++;
        }
        string ans;
        for(int k=i;k<=j;k++){
            ans.push_back(s[k]);
        }
        return ans;
    }
  
    string longestPalindrome(string &s) {
        // code here
        int n = s.size();
        int maximum = 1;
        //odd length palindrome
        for(int i=0;i<n;i++){
            int ptr1=i-1;
            int ptr2=i+1;
            while(ptr1>=0&&ptr2<n){
                if(s[ptr1]!=s[ptr2]){
                    break;
                }
                ptr1--;
                ptr2++;
            }
            maximum=max(maximum,(ptr2-ptr1-1));
        }
        //even length palindrome
        int i=0;
        int j=1;
        while(j<n){
            if(s[i]==s[j]){
                int ptr1=i-1;
                int ptr2=j+1;
                while(ptr1>=0&&ptr2<n){
                    if(s[ptr1]!=s[ptr2]){
                        break;
                    }
                    ptr1--;
                    ptr2++;
                }
                maximum=max(maximum,(ptr2-ptr1-1));
            }
            i++;
            j++;
        }
        return findpalindrome(s,n,maximum);
    }
};
