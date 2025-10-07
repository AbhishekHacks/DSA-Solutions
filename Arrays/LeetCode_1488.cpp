/*Your country has an infinite number of lakes. Initially, all the lakes are empty, but when it rains over the nth lake, the nth lake becomes full of water. If it rains over a lake that is full of water, there will be a flood. Your goal is to avoid floods in any lake.

Given an integer array rains where:

rains[i] > 0 means there will be rains over the rains[i] lake.
rains[i] == 0 means there are no rains this day and you can choose one lake this day and dry it.
Return an array ans where:

ans.length == rains.length
ans[i] == -1 if rains[i] > 0.
ans[i] is the lake you choose to dry in the ith day if rains[i] == 0.
If there are multiple valid answers return any of them. If it is impossible to avoid flood return an empty array.

Notice that if you chose to dry a full lake, it becomes empty, but if you chose to dry an empty lake, nothing changes.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1); 
        unordered_map<int, int> full; 
        set<int> dryDays; 
        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0) {
                int lake = rains[i];
                if (full.count(lake)) {  
                    auto it = dryDays.lower_bound(full[lake]);
                    if (it == dryDays.end()) {
                      return {}; 
                    }
                    ans[*it] = lake; 
                    dryDays.erase(it);
                }
                full[lake] = i;
                ans[i] = -1;
            } 
            else {
                dryDays.insert(i);
            }
        }
        return ans;
    }
};
