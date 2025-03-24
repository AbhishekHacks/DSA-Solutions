/*You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).

Return the count of days when the employee is available for work but no meetings are scheduled.

Note: The meetings may overlap.*/

//Time Complexity -- O(NlogN)

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        int n=meetings.size();

        //sort the meetings according to the start time
        sort(meetings.begin(),meetings.end(),[](const vector<int>&a,vector<int>&b){
            return a[0]<b[0];
        });

        //declaring two variables front and end to check the number of days free
        int end=0;
        int front=0;

        //variable to count the free days
        int count=0;

        //lets merge the meetings that overlap and store this in another 2D vector
        vector<vector<int>> merged;
        int i = 0;
        int j = 1;
        int opening1=meetings[i][0]; //first meeting opening time
        int closing1=meetings[i][1]; //first meeting closing time
        while(j<n){
            int opening2=meetings[j][0];
            int closing2=meetings[j][1];
            if(opening2<=closing1&&closing2>closing1){
                closing1=closing2; //if the two meetings overlap and the closing time of second meeting is greater just merge it
            }
            else if(opening2>closing1){
                vector<int>interval;
                interval.push_back(opening1);
                interval.push_back(closing1);
                merged.push_back(interval);
                
                //if the two meeting don't overlap just add the previous meeting to the merged vector and initialise opening1 and closing1 with opening2 and closing2
                opening1=opening2; 
                closing1=closing2;
            }

            //increment j
            j++;
        }

        //after the loop we still need to add the last meeting
        vector<int>interval;
        interval.push_back(opening1);
        interval.push_back(closing1);
        merged.push_back(interval);

        int l = merged.size();

        //iterate through the entire vector merged to count the days free
        for(int i=0;i<l;i++){
            front = merged[i][0];
            count+=(front-end-1);
            end=merged[i][1];
        }

        //finally count the days that are not counted after the last meeting
        count+=(days-end);

        //return the count
        return count;
    }
};
