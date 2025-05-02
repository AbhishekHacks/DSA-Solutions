/*Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.*/

//Time Complexity -- O(n)

class Solution {
public:
    int maxScore(string s) {

        int n = s.size();
        
        vector<int>prefix;
        vector<int>suffix;

        int count_0=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                count_0+=1;
            }
            prefix.push_back(count_0);
        }

        int count_1=0;
        suffix.push_back(0);
        for(int i=n-2;i>=0;i--){
            if(s[i+1]=='1'){
                count_1+=1;
            }
            suffix.push_back(count_1);
        }

        reverse(suffix.begin(),suffix.end());

        int maximum = INT_MIN;
        for(int i=0;i<n-1;i++){
            int sum = prefix[i]+suffix[i];
            if(maximum<sum){
                maximum = sum;
            }
        }

        return maximum;
    }
};
