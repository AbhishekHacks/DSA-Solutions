/*In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.*/

//Time Complexity -- O(N)

class Solution {
public:

    bool nottrust(int n,vector<vector<int>>& trust,int a){
        for(int i=0;i<trust.size();i++){
            if(trust[i][0]==a){
                return false;
            }
        }
        return true;
    }

    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1){
            return 1;
        }
        unordered_map<int,int>m;
        for(int i=0;i<trust.size();i++){
            m[trust[i][1]]++;
        }
        for(auto i:m){
            if(i.second==(n-1)){
                if(nottrust(n,trust,i.first)){
                    return i.first;
                }
                else{
                    return -1;
                }
            }
        }
        return -1;
    }
};
