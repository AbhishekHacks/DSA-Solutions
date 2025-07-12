/*Given two integers left and right, return the count of numbers in the inclusive range [left, right] having a prime number of set bits in their binary representation.

Recall that the number of set bits an integer has is the number of 1's present when written in binary.

For example, 21 written in binary is 10101, which has 3 set bits.*/

//Time Complexity -- O((right-left)*log(num))

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_map<int,int>m;
        m[2]=1;m[3]=1;m[5]=1;m[7]=1;m[11]=1;m[13]=1;m[17]=1;m[19]=1;
        int answer=0;
        for(int i=left;i<=right;i++){
            int num = i;
            int count=0;
            while(num>0){
                if((num&1)==1){
                    count++;
                }
                num=num>>1;
            }
            if(m.count(count)){
                answer++;
            }
        }
        return answer;
    }
};
