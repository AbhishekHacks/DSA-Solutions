/*Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

*/

//Time Complexity -- O(n)

class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char,int>m;
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        int count=0;
        bool oddlength=false;
        for(auto i:m){
            if(i.second%2!=0&&oddlength==false){
                count+=i.second;
                oddlength=true;
            }
            else if(i.second%2==0){
                count+=i.second;
            }
            else{
                count+=(i.second-1);
            }
        }
        return count;
    }
};
