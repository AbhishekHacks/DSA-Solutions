/*You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.

The right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.

Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.*/

//Optimised approach -- O(nlogn) , the brute force approach is uploaded in Arrays file with the same file name.

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        //Optimise
        vector<int>answer;
        vector<int>keys;
        unordered_map<int,int>map;
        //O(n)
        for(int i=0;i<intervals.size();i++){
            int start=intervals[i][0];
            keys.push_back(start);
            map[start]=i;
        }
        //O(nlogn)
        sort(keys.begin(),keys.end());
        //O(nlogn)
        for(int i=0;i<intervals.size();i++){
            int target=intervals[i][1];
            int start=0;
            int end=keys.size()-1;
            int ans=INT_MIN;
            while(start<=end){
                int mid=start+(end-start)/2;
                if(keys[mid]>=target){
                    ans=keys[mid];
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            if(ans==INT_MIN){
                answer.push_back(-1);
            }
            else{
                answer.push_back(map[ans]);
            }
        }
        return answer;
    }
};
