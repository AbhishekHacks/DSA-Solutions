/*The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.*/

//Time Complexity -- O(2^N)

class Solution {
public:
    string countAndSay(int n) {
        
        string s="1";
        if(n==1){
            return s;
        }

        for(int i=2;i<=n;i++){
            int len = s.size();
            char prev = s[0];
            int count=0;
            string temp;
            for(int j=0;j<len;j++){
                char curr = s[j];
                if(prev==curr){
                    count+=1;
                }
                else{
                    string numberstr = to_string(count);
                    temp.append(numberstr);
                    temp.push_back(prev);
                    count=0;
                    prev=curr;
                    j--;
                }
            }
            string numberstr = to_string(count);
            temp.append(numberstr);
            temp.push_back(prev);
            s=temp;
        }

        return s;
    }
};
