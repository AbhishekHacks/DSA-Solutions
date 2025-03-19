/*Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

*/

//Time Complexity -- O(N)

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int result=1;
        for(int i=0;i<b.size();i++){
            int element = 1;
            for(int j=1;j<=10;j++){
                element=(result*element)%1337;
            }
            result=element;
            long long power = 1;
            for(int j=1;j<=b[i];j++){
                power=(power*a)%1337;
            }
            result=(result*power)%1337;
        }
        return result;
    }
};
