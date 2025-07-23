/*A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
A self-dividing number is not allowed to contain the digit zero.

Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right] (both inclusive).*/

//Time Complexity -- O((right-left)*log(n))

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans; 
        for(int i=left;i<=right;i++){
            int num = i;
            bool isselfdividing = true;
            while(num>0){
                int r = num%10;
                if(r==0||i%r!=0){
                    isselfdividing = false;
                    break;
                }
                num/=10;
            }
            if(isselfdividing){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
