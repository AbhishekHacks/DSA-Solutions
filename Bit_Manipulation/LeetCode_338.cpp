/*Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int count=0;
            int element=i;
            while(element>0){
                int r = element&1;
                if(r==1){
                    count++;
                }
                element=element>>1;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
