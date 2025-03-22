/*Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.*/

//Time Complexity -- O(sqrt(c))

//Space Complexity -- O(1)

class Solution {
public:
    bool judgeSquareSum(int c) {

        //two pointer approach
        int i=0;
        int j=(int)sqrt(c);
        while(i<=j){
            long long sum = (long long)(i*i)+(j*j); //convert the sum to long long
            if(sum==c){
                //if sum is found to be equal to c
                return true;
            }
            else if(sum>c){
                j--;
            }
            else{
                i++;
            }
        }

        //if not found
        return false;
    }
};
