/*You are given a positive integer n.

A positive integer is a base-10 component if it is the product of a single digit from 1 to 9 and a non-negative power of 10. For example, 500, 30, and 7 are base-10 components, while 537, 102, and 11 are not.

Express n as a sum of only base-10 components, using the fewest base-10 components possible.

Return an array containing these base-10 components in descending order.*/

//Time Complexity -- O(log(n))

class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        int count=0;
        vector<int>answer;
        while(n>0){
            int r = n%10;
            if(r!=0){
                answer.push_back(r*pow(10,count));
            }
            n/=10;
            count++;
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};
