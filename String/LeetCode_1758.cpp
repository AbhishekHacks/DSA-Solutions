/*You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

Return the minimum number of operations needed to make s alternating.

*/

//Time Complexity --> O(n)

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        //let the first element be equal to 0
        int count0;
        if(s[0]=='0'){
            count0=0;
        }
        else{
            count0=1;
        }
        char prev = '0';
        for(int i=1;i<n;i++){
            char curr = s[i];
            if(prev==curr){
                if(curr=='0'){
                    curr='1';
                }
                else{
                    curr='0';
                }
                count0+=1;
            }
            prev = curr;
        }

        //let the first element be 1
        int count1;
        if(s[0]=='1'){
            count1=0;
        }
        else{
            count1=1;
        }
        prev = '1';
        for(int i=1;i<n;i++){
            char curr = s[i];
            if(prev==curr){
                if(curr=='0'){
                    curr='1';
                }
                else{
                    curr='0';
                }
                count1+=1;
            }
            prev = curr;
        }

        //calculate the minimum
        return min(count0,count1);
    }
};
