/*You are given two positive integers low and high.

An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. Numbers with an odd number of digits are never symmetric.

Return the number of symmetric integers in the range [low, high].

 */

//Time Complexity -- O(n)

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        
        int count=0;
        for(int i=low;i<=high;i++){
            if(i>=10&&i<=99){
                if(i%11==0){
                    count+=1;
                }
            }
            else if(i>=1000&&i<=9999){
                int element1 = i/100;
                int element2 = i%100;
                int sum1 = (element1/10) + (element1%10);
                int sum2 = (element2/10) + (element2%10);
                if(sum1==sum2){
                    count+=1;
                }
            }
        }

        return count;
    }
};
