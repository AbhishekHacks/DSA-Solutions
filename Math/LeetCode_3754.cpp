/*You are given an integer n.

Form a new integer x by concatenating all the non-zero digits of n in their original order. If there are no non-zero digits, x = 0.

Let sum be the sum of digits in x.

Return an integer representing the value of x * sum.*/

//Time Complexity -- O(log(n))

class Solution {
public:
    long long sumAndMultiply(int n) {
        string str = to_string(n);
        int l = str.size(),sum=0;
        string s;
        for(int i=0;i<l;i++){
            if(str[i]!='0'){
                s.push_back(str[i]);
                sum+=(str[i]-'0');
            }
        }
        if(s.empty()){
            return 0;
        }
        long long ans = stoi(s);
        return ans*sum;
    }
};
