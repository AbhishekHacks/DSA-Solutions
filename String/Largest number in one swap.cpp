/*Given a string s, return the lexicographically largest string that can be obtained by swapping at most one pair of characters in s.*/

//Time Complexity -- O(nlogn)

class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n = s.size();
        string largest = s;
        sort(largest.begin(),largest.end());
        reverse(largest.begin(),largest.end());
        int index = -1;
        char ch;
        for(int i=0;i<n;i++){
            if(largest[i]!=s[i]){
                ch = largest[i];
                index = i;
                break;
            }
        }
        if(index==-1){
            return s;
        }
        for(int i=n-1;i>=index+1;i--){
            if(s[i]==ch){
                swap(s[index],s[i]);
                break;
            }
        }
        return s;
    }
};
