/*Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.*/

//Time Complexity -- O(max(n1,n2))

class Solution {
public:
    string addStrings(string num1, string num2) {
        string str;
        int n1 = num1.size();
        int n2 = num2.size();
        int i=n1-1,j=n2-1;
        int carry=0;
        while(i>=0&&j>=0){
            int d1 = num1[i]-'0';
            int d2 = num2[j]-'0';
            int sum = d1+d2+carry;
            int temp = sum%10;
            char ch = temp+'0';
            str.push_back(ch);
            carry = sum/10;
            i--;
            j--;
        }
        while(i>=0){
            int d = num1[i]-'0';
            int sum = d+carry;
            int temp = sum%10;
            char ch = temp+'0';
            str.push_back(ch);
            carry=sum/10;
            i--;
        }
        while(j>=0){
            int d = num2[j]-'0';
            int sum = d+carry;
            int temp = sum%10;
            char ch = temp+'0';
            str.push_back(ch);
            carry=sum/10;
            j--;
        }
        if(carry!=0){
            char ch = carry+'0';
            str.push_back(ch);
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
