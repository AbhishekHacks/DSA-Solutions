/*You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:

An integer x.
Record a new score of x.
'+'.
Record a new score that is the sum of the previous two scores.
'D'.
Record a new score that is the double of the previous score.
'C'.
Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.

The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.*/

//Time Complexity -- O(n)

class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        vector<int>record;
        for(int i=0;i<n;i++){
            int len = record.size();
            if(operations[i]=="+"){
                int sum = record[len-1]+record[len-2];
                record.push_back(sum);
            }
            else if(operations[i]=="D"){
                int new_score = record[len-1]*2;
                record.push_back(new_score);
            }
            else if(operations[i]=="C"){
                record.pop_back();
            }
            else{
                int new_score = stoi(operations[i]);
                record.push_back(new_score);
            }
        }
        int ans = accumulate(record.begin(),record.end(),0);
        return ans;
    }
};
