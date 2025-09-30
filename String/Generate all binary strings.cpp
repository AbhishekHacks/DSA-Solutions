/*Given an integer n. You need to generate all the binary strings of n characters representing bits.

Note: Return the strings in  ascending order.*/

//Time Complexity -- O(n*(2^n))

class Solution {
  public:
    vector<string> binstr(int n) {
        // code here
        vector<string>answer;
        for(int i=0;i<=pow(2,n)-1;i++){
            int num = i;
            int count=0;
            string temp;
            while(count!=n){
                char r = (num&1)+'0';
                temp.push_back(r);
                num=num>>1;
                count++;
            }
            reverse(temp.begin(),temp.end());
            answer.push_back(temp);
        }
        return answer;
    }
};
