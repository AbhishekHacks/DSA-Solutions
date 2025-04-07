/*For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.*/

//Time Complexity -- O()

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        int n = str1.size();
        int m = str2.size();

        int i=0;
        string output="";
        string temp;
        while(i<m){
            temp.push_back(str2[i]);
            int len = temp.size();
            if(n%len!=0 || m%len!=0){
                i++;
                continue;
            }
            int factor1 = n/len;
            int factor2 = m/len;

            string s1="";
            string s2="";
            for(int j=1;j<=factor2;j++){
                s2.append(temp);
            }
            if(s2!=str2){
                i++;
                continue;
            }
            for(int j=1;j<=factor1;j++){
                s1.append(temp);
            }
            if(s1==str1){
                output = temp;
            }
            i++;
        }

        return output;
    }
};
