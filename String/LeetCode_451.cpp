/*Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int>m;
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        vector<vector<int>>freq;
        for(auto i:m){
            vector<int>temp;
            temp.push_back(i.first);
            temp.push_back(i.second);
            freq.push_back(temp);
        }
        sort(freq.begin(),freq.end(),[](const vector<int>&a,vector<int>&b){
            return a[1]>b[1];
        });
        int len = freq.size();
        string str;
        for(int i=0;i<len;i++){
            char ch = freq[i][0];
            int l = freq[i][1];
            for(int j=1;j<=l;j++){
                str.push_back(ch);
            }
        }
        return str;
    }
};
