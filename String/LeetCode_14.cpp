/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

*/

//Time Complexity -- O(n*s)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        string prefix;
        int startIndex=0;
        int s = strs[0].size();

        for(int i=0;i<s;i++){
            char ch = strs[0][i];
            bool match = true;
            for(int j=0;j<n;j++){
                if(ch!=strs[j][i]){
                    match=false;
                    break;
                }
            }
            if(match){
                prefix.push_back(ch);
            }
            else{
                break;
            }
        }

        //return the prefix
        return prefix;
    }
};
