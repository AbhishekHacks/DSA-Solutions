/*Given two binary strings a and b, return their sum as a binary string.

*/

//Time Complexity -- O(max(n,m))

class Solution {
public:
    string addBinary(string a, string b) {
        
        int n=a.size();
        int m=b.size();

        //output string
        string output;

        //define a carry
        char carry='0';

        //two pointers defined
        int i=n-1;
        int j=m-1;

        //run a loop
        while(i>=0&&j>=0){

            //if bits are 0
            if(a[i]=='0'&&b[j]=='0'){
                output.push_back(carry);
                carry='0';
            }

            //if bits are 1
            else if(a[i]=='1'&&b[j]=='1'){
                output.push_back(carry);
                carry='1';
            }

            //if bits are alternate
            else if((a[i]=='0'&&b[j]=='1')||(a[i]=='1'||b[j]=='0')){
                if(carry=='0'){
                    output.push_back('1');
                }
                else{
                    output.push_back('0');
                }
            }

            //decrement i and j
            i--;
            j--;
        }

        //j is finished
        while(i>=0){
            if(a[i]=='0'&&carry=='0'){
                output.push_back('0');
            }
            else if((a[i]=='0'&&carry=='1')||(a[i]=='1'&&carry=='0')){
                output.push_back('1');
                carry='0';
            }
            else if(a[i]=='1'&&carry=='1'){
                output.push_back('0');
                carry='1';
            }
            i--;
        }

        //when i finished
        while(j>=0){
            if(b[j]=='0'&&carry=='0'){
                output.push_back('0');
            }
            else if((b[j]=='0'&&carry=='1')||(b[j]=='1'&&carry=='0')){
                output.push_back('1');
                carry='0';
            }
            else if(b[j]=='1'&&carry=='1'){
                output.push_back('0');
                carry='1';
            }
            j--;
        }

        //final step is to see if we are left with any carry
        if(carry=='1'){
            output.push_back(carry);
        }

        reverse(output.begin(),output.end());

        //return the output
        return output;
    }
};
