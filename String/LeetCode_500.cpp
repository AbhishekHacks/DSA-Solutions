/*Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.

Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.

In the American keyboard:

the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".*/

//Time Complexity -- O(N*L)

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string>output;
        int n = words.size();
        unordered_map<char,int>k1;
        unordered_map<char,int>k2;
        unordered_map<char,int>k3;
        vector<string>kstring={"QWERTYUIOPqwertyuiop","ASDFGHJKLasdfghjkl","ZXCVBNMzxcvbnm"};
        for(int i=0;i<3;i++){
            if(i==0){
                for(int j=0;j<20;j++){
                    k1[kstring[0][j]]++;
                }
            }
            else if(i==1){
                for(int j=0;j<18;j++){
                    k2[kstring[1][j]]++;
                }
            }
            else{
                for(int j=0;j<14;j++){
                    k3[kstring[2][j]]++;
                }
            }
        }

        for(int i=0;i<n;i++){
            string temp = words[i];
            int a = 0;
            for(int j=0;j<temp.size();j++){
                if(k1.count(temp[j])==0){
                    a=1;
                    break;
                }
            }
            if(a==0){
                output.push_back(temp);
                continue;
            }
            a=0;
            for(int j=0;j<temp.size();j++){
                if(k2.count(temp[j])==0){
                    a=1;
                    break;
                }
            }
            if(a==0){
                output.push_back(temp);
                continue;
            }
            a=0;
            for(int j=0;j<temp.size();j++){
                if(k3.count(temp[j])==0){
                    a=1;
                    break;
                }
            }
            if(a==0){
                output.push_back(temp);
            }
        }

        return output;
    }
};
