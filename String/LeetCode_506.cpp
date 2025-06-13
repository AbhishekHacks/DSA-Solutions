/*You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        unordered_map<int,string>m;
        vector<int>temp(score);
        sort(temp.begin(),temp.end());
        for(int i=n-1;i>=0;i--){
            if(n-i==1){
                m[temp[i]]="Gold Medal";
            }
            else if(n-i==2){
                m[temp[i]]="Silver Medal";
            }
            else if(n-i==3){
                m[temp[i]]="Bronze Medal";
            }
            else{
                int rank = n-i;
                string str = to_string(rank);
                m[temp[i]]=str;
            }
        }
        vector<string>answer;
        for(int i=0;i<n;i++){
            answer.push_back(m[score[i]]);
        }
        return answer;
    }
};
