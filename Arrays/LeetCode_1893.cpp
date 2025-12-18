/*You are given a 2D integer array ranges and two integers left and right. Each ranges[i] = [starti, endi] represents an inclusive interval between starti and endi.

Return true if each integer in the inclusive range [left, right] is covered by at least one interval in ranges. Return false otherwise.

An integer x is covered by an interval ranges[i] = [starti, endi] if starti <= x <= endi.*/

//Time Complexity -- O(n*m)

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int n = ranges.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int start = ranges[i][0];
            int end = ranges[i][1];
            for(int j=start;j<=end;j++){
                m[j]++;
            }
        }
        for(int i=left;i<=right;i++){
            if(!m.count(i)){
                return false;
            }
        }
        return true;
    }
};
