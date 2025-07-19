/*Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order.

If a folder[i] is located within another folder[j], it is called a sub-folder of it. A sub-folder of folder[j] must start with folder[j], followed by a "/". For example, "/a/b" is a sub-folder of "/a", but "/b" is not a sub-folder of "/a/b/c".

The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.

For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not.
 */

//Time Complexity -- O(n*m)

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        unordered_map<string,int>m;
        for(int i=0;i<n;i++){
            m[folder[i]]++;
        }
        vector<string>output;
        for(int i=0;i<n;i++){
            bool subfolder = false;
            string s = folder[i];
            string str;
            for(int j=0;j<s.size()-1;j++){
                if(s[j]!='/'){
                    str.push_back(s[j]);
                }
                else{
                    if(m.count(str)){
                        subfolder = true;
                        break;
                    }
                    str.push_back(s[j]);
                }
            }
            if(!subfolder){
                output.push_back(s);
            }
        }
        return output;
    }
};
