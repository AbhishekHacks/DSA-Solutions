/*Given a string word, return the sum of the number of vowels ('a', 'e', 'i', 'o', and 'u') in every substring of word.

A substring is a contiguous (non-empty) sequence of characters within a string.

Note: Due to the large constraints, the answer may not fit in a signed 32-bit integer. Please be careful during the calculations.*/

//Time Complexity -- O(n)

class Solution {
public:
    long long countVowels(string word) {
        int n = word.size();
        long long ans=0;
        long long count=0;
        set<char>s={'a','e','i','o','u'};
        for(int i=0;i<n;i++){
            if(s.count(word[i])){
                count++;
            }
            ans+=count;
        }
        long long prev=ans;
        for(int i=0;i<n;i++){
            if(s.count(word[i])){
                prev=prev-n+i;
            }
            ans+=prev;
        }
        return ans;
    }
};
