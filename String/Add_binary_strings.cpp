/*Problem statement
You have been given two binary strings ‘A’ and ‘B’. Your task is to find the sum of both strings in the form of a binary string.

Binary strings are the representation of integers in the binary form. For example, the binary strings of 9 and 16 are “1001” and “10000” respectively.

*/

//Time Complexity -- O(max(n,m))

string addBinaryString(string &a, string &b, int n, int m)
{
    // Write your code here.

    //output string
    string output;

    char carry = '0';
    int i=n-1;
    int j=m-1;
    while(i>=0&&j>=0){
        if(a[i]=='0'&&b[j]=='0'&&carry=='0'){
            output.push_back(carry);
        }
        else if(a[i]=='0'&&b[j]=='0'&&carry=='1'){
            output.push_back(carry);
            carry='0';
        }
        else if(a[i]=='1'&&b[j]=='1'){
            output.push_back(carry);
            carry='1';
        }
        else if(a[i]=='1'||b[j]=='1'){
            if(carry=='0'){
                output.push_back('1');
            }
            else{
                output.push_back('0');
            }
        }
        i--;
        j--;
    }
    while(i>=0){
        if(a[i]=='0'){
            output.push_back(carry);
            carry='0';
        }
        else{
            if(carry=='0'){
                output.push_back('1');
            }
            else{
                output.push_back('0');
            }
        }
        i--;
    }
    while(j>=0){
        if(b[j]=='0'){
            output.push_back(carry);
            carry='0';
        }
        else{
            if(carry=='0'){
                output.push_back('1');
            }
            else{
                output.push_back('0');
            }
        }
        j--;
    }

    if(carry=='1'){
        output.push_back(carry);
    }

    //reverse the string and take the final string
    string final_string;
    for(int i=output.size()-1;i>=0;i--){
        final_string.push_back(output[i]);
    }

    return final_string;
}
