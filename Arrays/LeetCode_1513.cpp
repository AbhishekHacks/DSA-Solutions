/*Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 109 + 7.*/

//Time Complexity -- O(n)

class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        long long count = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                count++;
            }
            else{
                ans=(ans+(((count*(count+1))/2)%1000000007))%1000000007;
                count=0;
            }
        }
        ans=(ans+(((count*(count+1))/2)%1000000007))%1000000007;
        return ans;
    }
};
