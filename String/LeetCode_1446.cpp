/*The power of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string s, return the power of s.

*/

//Time Complexity -- O(n)

class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int maximum = INT_MIN;
        int count = 0;
        char prev = s[0];
        for(int i=0;i<n;i++){
            char curr = s[i];
            if(prev==curr){
                count+=1;
                maximum = max(maximum,count);
            }
            else{
                count=0;
                i--;
            }
            prev=curr;
        }
        return maximum;
    }
};
