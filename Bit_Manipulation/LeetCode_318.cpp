/*Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.*/

//Time Complexity -- O(n^2)

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int>bitmask(n,0);
        vector<int>lengths(n,0);
        for(int i=0;i<n;i++){
            for(char c:words[i]){
                bitmask[i]|=(1<<(c-'a'));
            }
            lengths[i]=words[i].size();
        }
        int maximum = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if((bitmask[i]&bitmask[j])==0){
                    maximum=max(maximum,(lengths[i]*lengths[j]));
                }
            }
        }
        return maximum;
    }
};
