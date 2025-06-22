/*A string s can be partitioned into groups of size k using the following procedure:

The first group consists of the first k characters of the string, the second group consists of the next k characters of the string, and so on. Each element can be a part of exactly one group.
For the last group, if the string does not have k characters remaining, a character fill is used to complete the group.
Note that the partition is done so that after removing the fill character from the last group (if it exists) and concatenating all the groups in order, the resultant string should be s.

Given the string s, the size of each group k and the character fill, return a string array denoting the composition of every group s has been divided into, using the above procedure.

 */

//Time Complexity -- O(n)

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int mod = s.size()%k;
        if(mod!=0){
            int extra = k-mod;
            for(int i=1;i<=extra;i++){
                s.push_back(fill);
            }
        }
        vector<string>answer;
        string str;
        for(int i=0;i<s.size();i++){
            if((i+1)%k==0){
                str.push_back(s[i]);
                answer.push_back(str);
                str.clear();
            }
            else{
                str.push_back(s[i]);
            }
        }
        return answer;
    }
};
