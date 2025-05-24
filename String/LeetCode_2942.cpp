/*You are given a 0-indexed array of strings words and a character x.

Return an array of indices representing the words that contain the character x.

Note that the returned array may be in any order.*/

//Time Complexity -- O(n*l)

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>output;
        int n = words.size();
        for(int i=0;i<n;i++){
            string s = words[i];
            if(s.find(x)!=-1){
                output.push_back(i);
            }
        }
        return output;
    }
};
