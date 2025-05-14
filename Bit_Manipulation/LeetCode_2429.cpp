/*Given two positive integers num1 and num2, find the positive integer x such that:

x has the same number of set bits as num2, and
The value x XOR num1 is minimal.
Note that XOR is the bitwise XOR operation.

Return the integer x. The test cases are generated such that x is uniquely determined.

The number of set bits of an integer is the number of 1's in its binary representation.

*/

//Time Complexity -- O(log(n))

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count_1_num1 = 0;
        int count_1_num2 = 0;
        int temp1 = num1;
        int temp2 = num2;
        while(temp1>0){
            if((temp1&1)==1){
                count_1_num1+=1;
            }
            temp1=temp1>>1;
        }
        while(temp2>0){
            if((temp2&1)==1){
                count_1_num2+=1;
            }
            temp2=temp2>>1;
        }
        int number=0;
        int i=0;
        if(count_1_num1==count_1_num2){
            return num1;
        }
        else if(count_1_num1>count_1_num2){
            while(num1>0){
                if((num1&1)==1){
                    if(count_1_num2==count_1_num1){
                        number+=pow(2,i);
                        count_1_num1--;
                        count_1_num2--;
                    }
                    else{
                        count_1_num1--;
                    }
                }
                num1=num1>>1;
                i++;
            }
        }
        else{
            int temp = num1;
            int count=0;
            while(temp>0){
                if((temp&1)==1){
                    number+=pow(2,i);
                    count+=1;
                }
                temp=temp>>1;
                i++;
            }
            int extra=count_1_num2-count;
            i=0;
            while(extra>0){
                if((num1&1)==0){
                    number+=pow(2,i);
                    extra--;
                }
                num1=num1>>1;
                i++;
            }
        }
        return number;
    }
};
