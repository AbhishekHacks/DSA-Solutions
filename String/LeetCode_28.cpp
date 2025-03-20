/*Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

*/

//Time Complexity -- O(N)

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
        int index=0;
        deque<int>d;
        while(i<haystack.size()){
            if(haystack[i]==needle[index]){
                if(index==0){
                    d.push_back(i);
                }
                index++;
                if(index==needle.size()){
                    return d.front();
                }
            }
            else{
                if(index>0){
                    i=d.front();
                    d.pop_front();
                    index=0;
                }
            }
            i++;
        }
        return -1;
    }
};
