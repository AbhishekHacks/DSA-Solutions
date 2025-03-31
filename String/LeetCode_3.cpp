/*Given a string s, find the length of the longest substring without duplicate characters.*/

//Time Complexity -- O(N)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();
        if(n==0){
            return 0;
        }

        unordered_map<char,int>m;

        //logic -- iterating the loop and meanwhile putting characters in the unordered_map and than if the character is found in the map just calculate the length of that substring , if more than previous store in highest

        int highest=INT_MIN;
        int i=0;
        int startIndex=0;
        while(i<n){

            //if not found , add the character in hashmap
            if(!m.count(s[i])){
                m[s[i]]++;
                i++;
            }

            //if found , compute the length of the substring
            else{
                int length = m.size();
                if(highest<length){
                    highest=length;
                }
                m.erase(s[startIndex++]);
            }
        }

        //for the last character , compute the highest length for the last time
        int length=m.size();
        if(highest<length){
            highest=length;
        }

        //return the length
        return highest;
    }
};
