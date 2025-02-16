/*Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.

  
Example 2:

Input: num = 0
Output: 0
*/

class Solution {
public:
    int addDigits(int num) {
        while(num>9){
            int sum=0;
            while(num>0){
                int r = num%10;
                sum+=r;
                num=num/10;
            }
            num=sum;
        }
        return num;
    }
};
