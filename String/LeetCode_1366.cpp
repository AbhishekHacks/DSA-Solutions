/*In a special ranking system, each voter gives a rank from highest to lowest to all teams participating in the competition.

The ordering of teams is decided by who received the most position-one votes. If two or more teams tie in the first position, we consider the second position to resolve the conflict, if they tie again, we continue this process until the ties are resolved. If two or more teams are still tied after considering all positions, we rank them alphabetically based on their team letter.

You are given an array of strings votes which is the votes of all voters in the ranking systems. Sort all teams according to the ranking system described above.

Return a string of all teams sorted by the ranking system.*/

//Time Complexity -- O(Nm+NlogN)

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        map<string,char>m;
        int s = votes[0].size();
        for(char ch='A';ch<='Z';ch++){
            string str;
            for(int i=0;i<n;i++){
                for(int j=0;j<s;j++){
                    if(votes[i][j]==ch){
                        char pos = j+'0';
                        str.push_back(pos);
                        break;
                    }
                }
            }
            if(str.size()>0){
                sort(str.begin(),str.end());
                str.push_back(ch);
                m[str]=ch;
            }
        }
        string ans;
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};
