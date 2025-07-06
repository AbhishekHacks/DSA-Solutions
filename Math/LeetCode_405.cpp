/*Given a 32-bit integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.

All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.

Note: You are not allowed to use any built-in library method to directly solve this problem.*/

//Time Complexity -- O(log16(num))

class Solution {
public:
    string toHex(int num) {
        long long n = 0;
        if(num<0){
            int count=0;
            long long num1=abs((long long)num);
            bool found = false;
            while(count<32){
                if(!found&&((num1&1)==1)){
                    n+=pow(2,count);
                    found=true;
                }
                else if(found&&((num1&1)==0)){
                    n+=pow(2,count);
                }
                num1=num1>>1;
                count++;
            }
        }
        else{
            n=num;
        }
        vector<char>vec = {'a','b','c','d','e','f'};
        string hex;
        while(n!=0){
            int r = n%16;
            char ch;
            if(r>=10){
                ch=vec[r%10];
            }
            else{
                ch=r+'0';
            }
            hex.push_back(ch);
            n/=16;
        }
        reverse(hex.begin(),hex.end());
        if(hex.size()==0){
            return "0";
        }
        return hex;
    }
};
