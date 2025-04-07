/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.*/

//Time Complexity -- O(N*N)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n = strs.size();
        vector<vector<string>>output;

        //take another vector string like strs to store the sorted string
        vector<string>temporary;

        //we have arramged all the strings of the given strs in ascending order which means now we can simply compare strings and check if they are equal
        for(int i=0;i<n;i++){
            vector<char>ch;
            string temp = strs[i];
            int stringlen = temp.size();
            for(int j =0;j<stringlen;j++){
                ch.push_back(temp[j]);
            }
            sort(ch.begin(),ch.end());
            string rep;
            for(int j=0;j<stringlen;j++){
                rep.push_back(ch[j]);
            }
            temporary.push_back(rep);
        }

        //simply for the first string check if there is any other string like that
        for(int i=0;i<n;i++){
            if(strs[i]=="-1"){
                continue;
            }
            vector<string>res;
            res.push_back(strs[i]);
            string s1 = temporary[i];
            for(int j=i+1;j<n;j++){
                string s2 = temporary[j];
                if(s1==s2){
                    res.push_back(strs[j]);
                    strs[j]="-1";
                }
            }
            output.push_back(res);
        }

        //return the output
        return output;
    }
};
