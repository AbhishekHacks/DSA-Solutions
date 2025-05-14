/*You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory.
A double period '..' represents the previous/parent directory.
Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.
The simplified canonical path should follow these rules:

The path must start with a single slash '/'.
Directories within the path must be separated by exactly one slash '/'.
The path must not end with a slash '/', unless it is the root directory.
The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
Return the simplified canonical path.*/

//Time Complexity -- O(N)

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string>s;
        string str;
        for(int i=1;i<n;i++){
            if(path[i]=='/'&&path[i-1]=='/'){
                continue;
            }
            else if(path[i]=='/'){
                if(!s.empty()&&str==".."){
                    s.pop();
                }
                else if(str=="."){
                    str.clear();
                    continue;
                }
                else if(str!=".."){
                    s.push(str);
                }
                str.clear();
            }
            else{
                str.push_back(path[i]);
            }
        }
        if(path[n-1]!='/'){
            if(!s.empty()&&str==".."){
                s.pop();
            }
            else if(str!=".."&&str!="."){
                s.push(str);
            }
        }
        string result;
        if(s.empty()){
            result="/";
        }
        while(!s.empty()){
            result = "/"+s.top()+result;
            s.pop();
        }
        return result;
    }
};
