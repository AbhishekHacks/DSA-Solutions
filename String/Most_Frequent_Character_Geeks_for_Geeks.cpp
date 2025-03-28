/*Given a string s of lowercase alphabets. The task is to find the maximum occurring character in the string s. If more than one character occurs the maximum number of times then print the lexicographically smaller character.

*/

//Time Complexity -- O(N)

class Solution {
  public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string& s) {
        // Your code here
        
        //take an unordered map to calculate the character with the maximum frequency
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        
        //now calculate the alphabet with maximum frequency and at the same time which is lexicographically smaller
        int highest=INT_MIN;
        int lexi=INT_MAX;
        char ch;
        for(auto i:m){
            if(highest<i.second){
                ch=i.first;
                lexi=i.first;
                highest=i.second;
            }
            else if(highest==i.second){
                if(lexi>i.first){
                    ch=i.first;
                    lexi=i.first;
                }
            }
        }
        
        //return the character
        return ch;
    }
};
