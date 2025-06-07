/*You are given two integer arrays x and y, each of length n. You must choose three distinct indices i, j, and k such that:

x[i] != x[j]
x[j] != x[k]
x[k] != x[i]
Your goal is to maximize the value of y[i] + y[j] + y[k] under these conditions. Return the maximum possible sum that can be obtained by choosing such a triplet of indices.

If no such triplet exists, return -1.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            if(m.count(x[i])){
                int already = m[x[i]];
                int newele = y[i];
                m[x[i]]=max(already,newele);
            }
            else{
                m[x[i]]=y[i];
            }
        }
        int mapsize = m.size();
        if(mapsize<3){
            return -1;
        }
        vector<int>arr;
        for(auto i:m){
            arr.push_back(i.second);
        }
        sort(arr.begin(),arr.end());
        return arr[mapsize-1]+arr[mapsize-2]+arr[mapsize-3];
    }
};
