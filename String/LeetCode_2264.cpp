/*You are given a string num representing a large integer. An integer is good if it meets the following conditions:

It is a substring of num with length 3.
It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:

A substring is a contiguous sequence of characters within a string.
There may be leading zeroes in num or a good integer.*/

//Time Complexity -- O(n)

class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int maximum = INT_MIN;
        string result;
        for(int i=0;i<n-2;i++){
            if(num[i]==num[i+1]&&num[i]==num[i+2]){
                int x = num[i]-'0';
                maximum = max(maximum,x);
                i+=2;
            }
        }
        if(maximum!=INT_MIN){
            char ch = maximum+'0';
            result.push_back(ch);
            result.push_back(ch);
            result.push_back(ch);
        }
        return result;
    }
};
