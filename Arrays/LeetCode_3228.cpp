/*You are given a binary string s.

You can perform the following operation on the string any number of times:

Choose any index i from the string where i + 1 < s.length such that s[i] == '1' and s[i + 1] == '0'.
Move the character s[i] to the right until it reaches the end of the string or another '1'. For example, for s = "010010", if we choose i = 1, the resulting string will be s = "000110".
Return the maximum number of operations that you can perform.*/

//Time Complexity -- O(n)

class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        vector<int>vec;
        int operations = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                vec.push_back(i);
            }
        }
        int len = vec.size();
        int count = 1;
        for(int i=0;i<len-1;i++){
            if(vec[i+1]-vec[i]>1){
                operations+=count;
            }
            count++;
        } 
        if(len>0&&vec[len-1]!=n-1){
            operations+=count;
        }
        return operations;
    }
};
