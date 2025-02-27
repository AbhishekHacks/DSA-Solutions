/*You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].*/

//This solution needs improvements , it will be updated but this gets accepted for all the test cases

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        if(intervals.size()==0){
            vector<int>temp;
            temp.push_back(newInterval[0]);
            temp.push_back(newInterval[1]);
            answer.push_back(temp);
            return answer;
        }
        int tempopen=newInterval[0];
        int tempclose=newInterval[1];
        int index=-1;
        for(int i=0;i<intervals.size();i++){
            int opening = intervals[i][0];
            int closing = intervals[i][1];
            if(tempopen<opening){
                vector<int>v;
                v.push_back(tempopen);
                v.push_back(tempclose);
                answer.push_back(v);
                index=i;
                break;
            }
            else{
                vector<int>v;
                v.push_back(opening);
                v.push_back(closing);
                answer.push_back(v);
            }
        }
        if(index==-1){
            vector<int>v;
            v.push_back(tempopen);
            v.push_back(tempclose);
            answer.push_back(v);
        }
        else{
            while(index<intervals.size()){
                vector<int>v;
                v.push_back(intervals[index][0]);
                v.push_back(intervals[index][1]);
                answer.push_back(v);
                index++;
            }
        }
        vector<vector<int>> final;
        int i=0;
        int j=i+1;
        while(j<answer.size()){
            int opening1=answer[i][0];
            int closing1=answer[i][1];
            int opening2=answer[j][0];
            int closing2=answer[j][1];
            if(opening2<=closing1){
                if(closing2>closing1){
                    answer[i][1]=closing2;
                }
                j++;
            }
            else{
                vector<int> vec;
                vec.push_back(opening1);
                vec.push_back(closing1);
                final.push_back(vec);
                i=j;
                j++;
            }
        }
        vector<int>vec;
        vec.push_back(answer[i][0]);
        vec.push_back(answer[i][1]);
        final.push_back(vec);
        return final;
    }
};
