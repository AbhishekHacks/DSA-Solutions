/*Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.*/

//Time Complexity -- O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        stack<int>s;
        s.push(temperatures[n-1]);
        vector<int>output(n,0);

        for(int i=n-2;i>=0;i--){
            int count = 1;
            int j = i+1;
            while(!s.empty()){
                if(temperatures[i]>=s.top()){
                    count+=output[j];
                    j+=output[j];
                    s.pop();
                }
                else{
                    output[i]=count;
                    s.push(temperatures[i]);
                    break;
                }
            }
            if(s.empty()){
                s.push(temperatures[i]);
            }
        }

        return output;
    }
};
