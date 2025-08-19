/*You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.*/

//Time Complexity -- O(nlogm)

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int>answer;
        for(int i=0;i<n;i++){
            int start = 0;
            int end = m-1;
            int index = -1;
            while(start<=end){
                int mid = start+(end-start)/2;
                if((long long)spells[i]*potions[mid]>=success){
                    index=mid;
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            if(index==-1){
                answer.push_back(0);
            }
            else{
                answer.push_back(m-index);
            }
        }
        return answer;
    }
};
