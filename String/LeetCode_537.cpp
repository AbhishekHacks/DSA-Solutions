/*A complex number can be represented as a string on the form "real+imaginaryi" where:

real is the real part and is an integer in the range [-100, 100].
imaginary is the imaginary part and is an integer in the range [-100, 100].
i2 == -1.
Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.*/

//Time Complexity -- O(n1+n2)

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int n1 = num1.size(),n2 = num2.size();
        string r1,r2,i1,i2;
        bool found = false;
        for(int i=0;i<n1;i++){
            if(!found&&num1[i]!='+'){
                r1.push_back(num1[i]);
            }
            else if(num1[i]=='+'){
                found = true;
            }
            else if(found&&num1[i]!='i'){
                i1.push_back(num1[i]);
            }
            else if(num1[i]=='i'){
                found = false;
            }
        }
        for(int i=0;i<n2;i++){
            if(!found&&num2[i]!='+'){
                r2.push_back(num2[i]);
            }
            else if(num2[i]=='+'){
                found = true;
            }
            else if(found&&num2[i]!='i'){
                i2.push_back(num2[i]);
            }
        }
        int real1=stoi(r1),real2=stoi(r2),imag1=stoi(i1),imag2=stoi(i2);
        int real = (real1*real2)+(imag1*imag2*-1);
        int imag = (real1*imag2)+(real2*imag1);
        string realtostring = to_string(real);
        string imagtostring = to_string(imag);
        string ans;
        ans.append(realtostring);
        ans.push_back('+');
        ans.append(imagtostring);
        ans.push_back('i');
        return ans;
    }
};
