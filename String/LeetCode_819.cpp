/*Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.

The words in paragraph are case-insensitive and the answer should be returned in lowercase.

Note that words can not contain punctuation symbols.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int n = paragraph.size();
        string s;
        vector<string>words;
        for(int i=0;i<n;i++){
            if(paragraph[i]>=65&&paragraph[i]<=90){
                paragraph[i]+=32;
            }
            if(paragraph[i]<'a'||paragraph[i]>'z'){
                if(s.size()>0){
                    words.push_back(s);
                }
                s.clear();
            }
            else{
                s.push_back(paragraph[i]);
            }
        }
        if(s.size()>0){
            words.push_back(s);
        }
        unordered_map<string,int>m;
        for(int i=0;i<banned.size();i++){
            m[banned[i]]++;
        }
        sort(words.begin(),words.end());
        string prev=words[0];
        int count=0;
        int maximum=INT_MIN;
        string result;
        for(int i=0;i<words.size();i++){
            string curr=words[i];
            if(prev==curr){
                count+=1;
            }
            else{
                if(maximum<count){
                    if(!m.count(prev)){
                        result=prev;
                        maximum=count;
                    }
                }
                i--;
                count=0;
            }
            prev=curr;
        }
        if(maximum<count){
            if(!m.count(prev)){
                result=prev;
            }
        }
        return result;
    }
};
