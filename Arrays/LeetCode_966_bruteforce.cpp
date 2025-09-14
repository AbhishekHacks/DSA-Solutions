/*Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.

For a given query word, the spell checker handles two categories of spelling mistakes:

Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
In addition, the spell checker operates under the following precedence rules:

When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
When the query matches a word up to capitlization, you should return the first such match in the wordlist.
When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
If the query has no matches in the wordlist, you should return the empty string.
Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].*/

//Time Complexity -- O(n*m*k)

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        set<char>s = {'a','e','i','o','u'};
        int n = wordlist.size();
        int m = queries.size();
        unordered_map<string,int>m_wordlist;
        for(int i=0;i<n;i++){
            m_wordlist[wordlist[i]]++;
        }
        vector<string>ans;
        for(int i=0;i<m;i++){
            string temp = queries[i];
            string extra = temp;
            //matching exact -- 1st
            if(m_wordlist.count(temp)){
                ans.push_back(temp);
                continue;
            }
            //capitalization
            transform(temp.begin(),temp.end(),temp.begin(),::tolower);
            bool found = false;
            for(int j=0;j<n;j++){
                string word = wordlist[j];
                string extra_word = word;
                transform(word.begin(),word.end(),word.begin(),::tolower);
                if(temp==word){
                    ans.push_back(extra_word);
                    found = true;
                    break;
                }
            }
            if(found){
                continue;
            }
            //vowel errors -- 2nd
            for(int j=0;j<n;j++){
                string word = wordlist[j];
                string extra_word = word;
                transform(word.begin(),word.end(),word.begin(),::tolower);
                if(temp.size()!=word.size()){
                    continue;
                }
                bool replaceable = true;
                for(int k=0;k<word.size();k++){
                    if((s.count(temp[k])&&!s.count(word[k]))||(s.count(word[k])&&!s.count(temp[k]))||(!s.count(temp[k])&&!s.count(word[k])&&temp[k]!=word[k])){
                        replaceable = false;
                        break;
                    }
                }
                if(replaceable){
                    ans.push_back(extra_word);
                    found = true;
                    break;
                }
            }
            if(found){
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};
