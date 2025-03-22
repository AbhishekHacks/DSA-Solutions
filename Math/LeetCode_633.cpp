/*Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.*/

//Time Complexity -- O(sqrt(c))

class Solution {
public:
    bool judgeSquareSum(int c) {
        
        //calculate the square of every number and store it in vector
        vector<int>v;
        for(int i=0;i<=(int)sqrt(c);i++){
            v.push_back((i*i));
        }

        //two pointer approach
        int i=0;
        int j=v.size()-1;
        while(i<=j){
            long long sum = (long long)v[i]+v[j]; //convert the sum to long long
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
