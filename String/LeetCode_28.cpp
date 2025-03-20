/*Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

*/

//Time Complexity -- O(length of string)

class Solution {
public:
    int strStr(string haystack, string needle) {
        int index=0;
        int ans=-1;
        for(int i=0;i<haystack.length();i++){
            if(index==needle.length()){
                break;
            }
            if(haystack[i]==needle[index]){
                if(ans==-1){
                    ans=i;
                }
                index++;
            }
            else{
                ans=-1;
                index=0;
            }
        }
        return ans;
    }
};
