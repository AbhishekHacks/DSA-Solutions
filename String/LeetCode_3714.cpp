/*You are given a string s consisting only of the characters 'a', 'b', and 'c'.

A substring of s is called balanced if all distinct characters in the substring appear the same number of times.

Return the length of the longest balanced substring of s.*/

//Time Complexity -- O(nlogn)

class Solution {
public:

    int twocharacterlength(string &s,int n,char x,char y){
        int cx=0;
        int cy=0;
        unordered_map<int,int>m;
        m[0]=-1;
        int maximum = 0;
        for(int i=0;i<n;i++){
            if(s[i]==x){
                cx++;
            }
            else if(s[i]==y){
                cy++;
            }
            else{
                cx=0; cy=0;
                m.clear();
                m[0]=i; 
                continue;
            }
            int diff = cx-cy;
            if(!m.count(diff)){
                m[diff]=i;
            }
            else{
                maximum = max(maximum,i-m[diff]);
            }
        }
        return maximum;
    }

    int threecharacterlength(string &s,int n){
        int ca=0;
        int cb=0;
        int cc=0;
        map<pair<int,int>,int>m;
        m[{0,0}]=-1;
        int maximum = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                ca++;
            }
            else if(s[i]=='b'){
                cb++;
            }
            else{
                cc++;
            }
            int diff1 = ca-cb;
            int diff2 = ca-cc;
            if(!m.count({diff1,diff2})){
                m[{diff1,diff2}]=i;
            }
            else{
                maximum = max(maximum,i-m[{diff1,diff2}]);
            }
        }
        return maximum;
    }

    int longestBalanced(string s) {
        int n = s.size();
        //single character
        int maximum1 = 1;
        char prev = s[0];
        int count=1;
        for(int i=1;i<n;i++){
            char curr = s[i];
            if(prev==curr){
                count++;
                maximum1 = max(maximum1,count);
            }
            else{
                count=1;
            }
            prev=curr;
        }
        //two characters
        int maximum2_1 = twocharacterlength(s,n,'a','b');
        int maximum2_2 = twocharacterlength(s,n,'b','c');
        int maximum2_3 = twocharacterlength(s,n,'a','c');
        int maximum2 = max(maximum2_1,maximum2_2);
        maximum2 = max(maximum2,maximum2_3);
        //three characters
        int maximum3 = threecharacterlength(s,n);
        int maximum = max(maximum1,maximum2);
        return max(maximum,maximum3);
    }
};
