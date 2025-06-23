/*Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.*/

//Time Complexity -- O(d(n)*n) where d(n) is the number of factors of length of string

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if(n==1){
            return false;
        }
        vector<int>factors;
        factors.push_back(1);
        for(int i=2;i<=sqrt(n);i++){ //store all the factors
            if(n%i==0){
                factors.push_back(i);
                factors.push_back(n/i);
            }
        }
        for(int i:factors){
            string str;
            for(int j=0;j<i;j++){
                str.push_back(s[j]);
            }
            int index=0;
            bool found = true;
            for(int j=i;j<n;j++){
                if(str[index%i]!=s[j]){
                    found=false;
                    break;
                }
                index++;
            }
            if(found){
                return true;
            }
        }
        return false;
    }   
};
