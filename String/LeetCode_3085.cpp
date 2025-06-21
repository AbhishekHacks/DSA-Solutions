/*You are given a string word and an integer k.

We consider word to be k-special if |freq(word[i]) - freq(word[j])| <= k for all indices i and j in the string.

Here, freq(x) denotes the frequency of the character x in word, and |y| denotes the absolute value of y.

Return the minimum number of characters you need to delete to make word k-special.

*/

//Time Complexity -- O(N)

class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();
        unordered_map<char,int>m;
        for(int i=0;i<n;i++){
            m[word[i]]++;
        }
        vector<int>freq;
        for(auto i:m){
            freq.push_back(i.second);
        }
        int len = freq.size();
        int minimum = INT_MAX;
        for(int i=0;i<len;i++){
            int count=0;
            int x = freq[i];
            int max_freq = x+k;
            int index = i;
            for(int j=0;j<len;j++){
                if(j!=index){
                    if(freq[j]<x){
                        count+=freq[j];
                    }
                    else{
                        int diff = freq[j]-max_freq;
                        if(diff<=0){
                            diff=0;
                        }
                        count+=diff;
                    }
                }
            }
            minimum = min(minimum,count);
        }
        return minimum;
    }
};
