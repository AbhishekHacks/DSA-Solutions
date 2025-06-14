/*You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.

Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.

Notes:

When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
Bob can remap a digit to itself, in which case num does not change.
Bob can remap different digits for obtaining minimum and maximum values respectively.
The resulting number after remapping can contain leading zeroes.*/

//Time Complexity -- O(log10(num))

class Solution {
public:
    int minMaxDifference(int num) {
        vector<int>maximumvec;
        vector<int>minimumvec;
        while(num>0){
            int r = num%10;
            maximumvec.push_back(r);
            minimumvec.push_back(r);
            num/=10;
        }
        reverse(maximumvec.begin(),maximumvec.end());
        reverse(minimumvec.begin(),minimumvec.end());
        //lets create maximum and minimum values
        int digits = maximumvec.size();
        int replaceval = 0;
        bool nhimila = true;
        for(int i=0;i<digits;i++){
            if(maximumvec[i]!=9&&nhimila){
                replaceval=maximumvec[i];
                maximumvec[i]=9;
                nhimila=false;
            }
            else if(maximumvec[i]==replaceval&&!nhimila){
                maximumvec[i]=9;
            }
        }
        //lets create minimum value
        nhimila=true;
        for(int i=0;i<digits;i++){
            if(minimumvec[i]!=0&&nhimila){
                replaceval=minimumvec[i];
                minimumvec[i]=0;
                nhimila=false;
            }
            else if(minimumvec[i]==replaceval&&!nhimila){
                minimumvec[i]=0;
            }
        }
        int maximumvalue=0;
        int minimumvalue=0;
        for(int i=0;i<digits;i++){
            maximumvalue=(maximumvalue*10)+maximumvec[i];
            minimumvalue=(minimumvalue*10)+minimumvec[i];
        }
        return maximumvalue-minimumvalue;
    }
};
