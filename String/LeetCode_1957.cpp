/*A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.

 */

//Time Complexity -- O(n)

class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string ans;
        ans.push_back(s[0]);
        int count=1;
        for(int i=1;i<n;i++){
            if(ans.back()==s[i]){
                count+=1;
                if(count<=2){
                    ans.push_back(s[i]);
                }
            }
            else{
                ans.push_back(s[i]);
                count=1;
            }
        }
        return ans;
    }
};
