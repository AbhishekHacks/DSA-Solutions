/*You are given an integer array order of length n and an integer array friends.

order contains every integer from 1 to n exactly once, representing the IDs of the participants of a race in their finishing order.
friends contains the IDs of your friends in the race sorted in strictly increasing order. Each ID in friends is guaranteed to appear in the order array.
Return an array containing your friends' IDs in their finishing order.*/

//Time Complexity -- O(n+m)

class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int>ans;
        int m = friends.size();
        unordered_map<int,int>ma;
        for(int i=0;i<m;i++){
            ma[friends[i]]++;
        }
        int n = order.size();
        for(int i=0;i<n;i++){
            if(ma.count(order[i])){
                ans.push_back(order[i]);
            }
        }
        return ans;
    }
};
