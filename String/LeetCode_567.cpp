/*Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.*/

//Time Complexity -- O(n*m)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n=s1.size();
        int m=s2.size();

        //sliding window concept -- try to search in the substring of length n
        for(int i=0;i<m;i++){

            //take another unordered_map m2 for substring of length n in s2
            unordered_map<char,int>m2;
            for(int j=i;j<n+i;j++){

                //if no substring is found of length n till the end of s2 return false
                if(j==m){
                    return false;
                }
                
                m2[s2[j]]++;
            }

            //now lets see if this substring is a permutation of s1
            for(int j=0;j<n;j++){
                if(m2.count(s1[j])){
                    int value = m2[s1[j]];
                    if(value==1){
                        m2.erase(s1[j]);
                    }
                    else{
                        m2[s1[j]]=value-1;
                    }
                }
                else{
                    break;
                }
            }

            //lets check whether our unordered_map m2 size is 0 if yes than return true
            if(m2.size()==0){
                return true;
            }
        }

        //after every possibility if no permutation is found
        return false;
    }
};
