/*You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.*/

//Time Complexity -- O(n)

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int i=0;
        int bulls=0;
        int cows=0;
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        while(i<n){
            if(secret[i]==guess[i]){
                bulls+=1;
            }
            else{
                m1[secret[i]]++;
                m2[guess[i]]++;
            }
            i++;
        }
        for(auto j:m1){
            if(m2.count(j.first)){
                int val = m2[j.first];
                cows+=min(j.second,val);
            }
        }
        string str;
        string temp1 = to_string(bulls);
        string temp2 = to_string(cows);
        str.append(temp1);
        str.append("A");
        str.append(temp2);
        str.append("B");
        return str;
    }
};
