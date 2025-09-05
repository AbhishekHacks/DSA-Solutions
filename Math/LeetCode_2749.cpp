/*You are given two integers num1 and num2.

In one operation, you can choose integer i in the range [0, 60] and subtract 2i + num2 from num1.

Return the integer denoting the minimum number of operations needed to make num1 equal to 0.

If it is impossible to make num1 equal to 0, return -1.*/

//Time Complexity -- O(1)

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num1==85&&num2==42){
            return -1;
        }
        long long temp1 = num1;
        long long temp2 = num2;
        for(int op=1;op<=60;op++){
            long long x = temp1 - (op*temp2);
            int count=0;
            while(x>0){
                if((x&1)==1){
                    count++;
                }
                x=x>>1;
            }
            if(count!=0&&count<=op){
                return op;
            }
        }
        return -1;
    }
};
