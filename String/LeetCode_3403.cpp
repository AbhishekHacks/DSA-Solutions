/*You are given a string word, and an integer numFriends.

Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:

word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
All the split words are put into a box.
Find the lexicographically largest string from the box after all the rounds are finished.*/

//Time Complexity -- O(n^2)

class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1){
            return word;
        }
        int n = word.size();
        int maximum=INT_MIN;
        for(int i=0;i<n;i++){
            if(maximum<word[i]){
                maximum = word[i];
            }
        }
        vector<int>vec;
        for(int i=0;i<n;i++){
            if(word[i]==maximum){
                vec.push_back(i);
            }
        }
        vector<string>lexicolar;
        for(int i=0;i<vec.size();i++){
            string s;
            int endindex;
            int index=vec[i];
            if(index>=numFriends-1){
                endindex=n-1;
            }
            else{
                int remaining_split=numFriends-1-index;
                endindex=n-remaining_split-1;
            }
            for(int i=index;i<=endindex;i++){
                s.push_back(word[i]);
            }
            lexicolar.push_back(s);
        }
        sort(lexicolar.begin(),lexicolar.end());
        return lexicolar[lexicolar.size()-1];
    }
};
