/*Given an integer n, find the digit that occurs least frequently in its decimal representation. If multiple digits have the same frequency, choose the smallest digit.

Return the chosen digit as an integer.

The frequency of a digit x is the number of times it appears in the decimal representation of n.*/

//Time Complexity -- O(logn)

class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int,int>m;
        while(n>0){
            int r = n%10;
            m[r]++;
            n/=10;
        }
        int minimum = INT_MAX;
        int answer;
        for(auto i:m){
            if(minimum>i.second){
                answer=i.first;
                minimum = i.second;
            }
            else if(minimum==i.second){
                answer=min(answer,i.first);
            }
        }
        return answer;
    }
};
