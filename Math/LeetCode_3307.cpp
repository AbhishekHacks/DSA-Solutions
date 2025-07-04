/*Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k. You are also given an integer array operations, where operations[i] represents the type of the ith operation.

Now Bob will ask Alice to perform all operations in sequence:

If operations[i] == 0, append a copy of word to itself.
If operations[i] == 1, generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word. For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
Return the value of the kth character in word after performing all the operations.

Note that the character 'z' can be changed to 'a' in the second type of operation.*/

//Time Complexity -- O(log2(k))

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long op = ceil(log2(k));
        long long len = pow(2,op);
        int count=0;
        while(len>1){
            k = k%len;
            if(k==0){
                k=len;
            }
            len/=2;
            if(k>len){
                if(operations[op-1]==1){
                    count+=1;
                }
            }
            op--;
        }
        return 'a'+(count%26);
    }
};
