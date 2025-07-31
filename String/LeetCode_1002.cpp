/*Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.*/

//Time Complexity -- O(n*k)

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        unordered_map<char,int>m;
        for(char ch='a';ch<='z';ch++){
            int minimum = INT_MAX;
            for(int i=0;i<n;i++){
                string str = words[i];
                int count = 0;
                for(int j=0;j<str.size();j++){
                    if(str[j]==ch){
                        count+=1;
                    }
                }
                minimum = min(minimum,count);
            }
            m[ch]=minimum;
        }
        vector<string>ans;
        for(auto i:m){
            for(int j=1;j<=i.second;j++){
                string s(1,i.first);
                ans.push_back(s);
            }
        }
        return ans;
    }
};
