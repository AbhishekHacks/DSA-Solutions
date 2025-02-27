/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.*/
//Time Complexity -- O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> answer;
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a , const vector<int>& b){
            return a[0]<b[0];
        });
        int i=0;
        int j=i+1;
        while(j<n){
            int opening1 = intervals[i][0];
            int closing1 = intervals[i][1];
            int opening2 = intervals[j][0];
            int closing2 = intervals[j][1];
            if(opening2<=closing1){
                if(closing2>closing1){
                    intervals[i][1]=closing2;
                }
                j++;
            }
            else{
                vector<int> v;
                v.push_back(opening1);
                v.push_back(closing1);
                answer.push_back(v);
                i=j;
                j++;
            }
        }
        vector<int> v;
        v.push_back(intervals[i][0]);
        v.push_back(intervals[i][1]);
        answer.push_back(v);
        return answer;
    }
};
