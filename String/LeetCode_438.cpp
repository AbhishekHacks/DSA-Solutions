/*Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.*/

//Time Complexity -- O(n+m)

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>answer;
        unordered_map<char,int>mp;
        unordered_map<char,int>ms;
        for(int i=0;i<p.size();i++){
            mp[p[i]]++;
        }
        for(int i=0;i<p.size();i++){
            ms[s[i]]++;
        }
        if(mp.size()==ms.size()){
            bool same = true;
            for(auto i:mp){
                //every distinct character is present and with the equal amount failing one of these leads to not equal of maps
                if(ms.count(i.first)==0){
                    same=false;
                    break;
                }
                else{
                    if(ms[i.first]!=i.second){
                        same=false;
                        break;
                    }
                }
            }
            if(same){
                answer.push_back(0);
            }
        }
        int index=0;
        for(int i=p.size();i<s.size();i++){
            ms[s[index]]--;
            if(ms[s[index]]==0){
                ms.erase(s[index]);
            }
            ms[s[i]]++;
            bool same = true;
            for(char ch = 'a';ch<='z';ch++){
                //case -1 character present in both but not in equal amount
                if(mp.count(ch)&&ms.count(ch)){
                    if(mp[ch]!=ms[ch]){
                        same=false;
                        break;
                    }
                }
                //case -2 present in either of them so not anagram
                else if(mp.count(ch)||ms.count(ch)){
                    same=false;
                    break;
                }
                //case 3 exists that the character is not present in any of the map so in that case we dont perform anything so we wont write this case
            }
            index++;
            if(same){
                answer.push_back(index);
            }
        }
        return answer;
    }
};
