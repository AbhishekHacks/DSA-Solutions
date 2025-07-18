/*Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.*/

//Time Complexity -- O(n)

class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();
        int count=0;
        int a=0;
        int ind = 2*k;
        for(int i=0;i<n;i++){
            int start = (ind*count);
            int end = start+k-1;
            if(end>n-1){
                end=n-1;
            }
            if(start<=i&&i<=(start+end)/2){
                swap(s[i],s[end-a]);
                a++;
            }
            else{
                count++;
                i=(ind*count)-1;
                a=0;
            }
        }
        return s;
    }
};
