/*Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.

To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as 0.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.*/

//Time Complexity -- O(n)

class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int i=0;
        int j=0;
        int len1 = version1.size();
        int len2 = version2.size();
        string s1="";
        string s2="";

        while(i<len1&&j<len2){
            if(version1[i]!='.'){
                s1.push_back(version1[i]);
                i++;
            }
            if(version2[j]!='.'){
                s2.push_back(version2[j]);
                j++;
            }
            if(i<len1&&j<len2&&version1[i]=='.'&&version2[j]=='.'){
                int a = stoi(s1);
                int b = stoi(s2);
                if(a<b){
                    return -1;
                }
                else if(a>b){
                    return 1;
                }
                else{
                    s1.clear();
                    s2.clear();
                    i++;
                    j++;
                }
            }
        }

        while(i<len1){
            if(version1[i]!='.'){
                s1.push_back(version1[i]);
            }
            else{
                int a = stoi(s1);
                int b = stoi(s2);
                if(a<b){
                    return -1;
                }
                else if(a>b){
                    return 1;
                }
                else{
                    s1.clear();
                    s2="0";
                }
            }
            i++;
        }

        while(j<len2){
            if(version2[j]!='.'){
                s2.push_back(version2[j]);
            }
            else{
                int a = stoi(s1);
                int b = stoi(s2);
                if(a<b){
                    return -1;
                }
                else if(a>b){
                    return 1;
                }
                else{
                    s1="0";
                    s2.clear();
                }
            }
            j++;
        }

        int a = stoi(s1);
        int b = stoi(s2);
        if(a<b){
            return -1;
        }
        else if(a>b){
            return 1;
        }

        return 0;
    }
};
