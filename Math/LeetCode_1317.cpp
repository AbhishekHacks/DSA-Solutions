/*No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.

Given an integer n, return a list of two integers [a, b] where:

a and b are No-Zero integers.
a + b = n
The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.

 */

//Time Complexity -- O(nlogn)

class Solution {
public:
    bool contain_zero(int num){
        while(num>0){
            int r = num%10;
            if(r==0){
                return true;
            }
            num/=10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans;
        for(int a=1;a<=n-1;a++){
            int b = n-a;
            if(!contain_zero(a)&&!contain_zero(b)){
                ans.push_back(a);
                ans.push_back(b);
                break;
            }
        }
        return ans;
    }
};
