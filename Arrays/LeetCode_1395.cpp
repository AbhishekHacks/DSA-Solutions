/*There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).*/

//Time Complexity -- O(n^2)

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int>prefix1(n,0);
        vector<int>suffix1(n,0);
        vector<int>prefix2(n,0);
        vector<int>suffix2(n,0);
        set<int>s_prefix1;
        set<int>s_suffix1;
        set<int>s_prefix2;
        set<int>s_suffix2;
        //rating[i]<rating[j]<rating[k]
        for(int i=0;i<n;i++){
            s_prefix1.insert(rating[i]);
            prefix1[i] = distance(s_prefix1.begin(),s_prefix1.find(rating[i]));
        }
        for(int i=n-1;i>=0;i--){
            s_suffix1.insert(rating[i]);

            suffix1[i] = distance(s_suffix1.find(rating[i]),s_suffix1.end())-1;
        }
        //rating[i]>rating[j]>rating[k]
        for(int i=n-1;i>=0;i--){
            s_prefix2.insert(rating[i]);
            prefix2[i] = distance(s_prefix2.begin(),s_prefix2.find(rating[i]));
        }
        for(int i=0;i<n;i++){
            s_suffix2.insert(rating[i]);

            suffix2[i] = distance(s_suffix2.find(rating[i]),s_suffix2.end())-1;
        }
        //calculate how many satisfy
        int answer = 0;
        for(int i=0;i<n;i++){
            answer+=((prefix1[i]*suffix1[i])+(prefix2[i]*suffix2[i]));
        }
        return answer;
    }
};
