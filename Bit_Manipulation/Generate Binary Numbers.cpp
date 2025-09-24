/*Given a number n. The task is to generate all binary numbers with decimal values from 1 to n.*/

//Time Complexity -- O(nlog2n)

class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        vector<string>ans;
        for(int i=1;i<=n;i++){
            int num=i;
            string temp;
            while(num>0){
                char r = (num%2)+'0';
                temp.push_back(r);
                num/=2;
            }
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};
