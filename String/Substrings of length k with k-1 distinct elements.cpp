/*Given a string s consisting only lowercase alphabets and an integer k. Find the count of all substrings of length k which have exactly k-1 distinct characters.*/

//Time Complexity -- O(n)

class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        unordered_map<char,int>m;
        for(int i=0;i<k;i++){
            m[s[i]]++;
        }
        int count=0;
        if(m.size()==k-1){
            count++;
        }
        int index=0;
        for(int i=k;i<s.size();i++){
            m[s[i]]++;
            m[s[index]]--;
            if(m[s[index]]==0){
                m.erase(s[index]);
            }
            if(m.size()==k-1){
                count++;
            }
            index++;
        }
        return count;
    }
};
