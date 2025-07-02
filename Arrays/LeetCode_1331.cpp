/*Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        unordered_map<int,int>t;
        int count=1;
        for(auto i:m){
            t[i.first]=count;
            count++;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=t[arr[i]];
        }
        return arr;
    }
};
