/*Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

*/

//Time Complexity -- O(k*n)

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>output;
        int n = words.size();
        unordered_map<string,int>m;
        for(int i=0;i<n;i++){
            m[words[i]]++;
        }
        for(int i=1;i<=k;i++){
            int maximum = INT_MIN;
            string str;
            for(auto i:m){
                if(maximum<i.second){
                    maximum = i.second;
                    str=i.first;
                }
                else if(maximum==i.second){
                    if(str>i.first){
                        str=i.first;
                    }
                }
            }
            output.push_back(str);
            m.erase(str);
        }
        return output;
    }
};
