/*You are given a string array words, consisting of distinct 4-letter strings, each containing lowercase English letters.

A word square consists of 4 distinct words: top, left, right and bottom, arranged as follows:

top forms the top row.
bottom forms the bottom row.
left forms the left column (top to bottom).
right forms the right column (top to bottom).
It must satisfy:

top[0] == left[0], top[3] == right[0]
bottom[0] == left[3], bottom[3] == right[3]
Return all valid distinct word squares, sorted in ascending lexicographic order by the 4-tuple (top, left, right, bottom)​​​​​​​.*/

//Time Complexity -- O(N^4log(N))

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            string top = words[i];
            for(int j=0;j<n;j++){
                string bottom = words[j];
                if(j==i){
                    continue;
                }
                for(int k=0;k<n;k++){
                    string left = words[k];
                    if(k!=i&&k!=j&&top[0]==left[0]&&bottom[0]==left[3]){
                        for(int l=0;l<n;l++){
                            string right = words[l];
                            if(l!=i&&l!=k&&l!=j&&top[3]==right[0]&&bottom[3]==right[3]){
                                vector<string>temp;
                                temp.push_back(top);
                                temp.push_back(left);
                                temp.push_back(right);
                                temp.push_back(bottom);
                                ans.push_back(temp);
                            }
                        }
                    }
                } 
            }
        }
        sort(ans.begin(),ans.end(),[](const vector<string>a,vector<string>b){
            if(a[0]==b[0]){
                if(a[1]==b[1]){
                    if(a[2]==b[2]){
                        return a[3]<b[3];
                    }
                    else{
                        return a[2]<b[2];
                    }
                }
                else{
                    return a[1]<b[1];
                }
            }
            else{
                return a[0]<b[0];
            }
        });
        return ans;
    }
};
