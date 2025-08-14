/*Given a string s and a character c that occurs in s, return an array of integers answer where answer.length == s.length and answer[i] is the distance from index i to the closest occurrence of character c in s.

The distance between two indices i and j is abs(i - j), where abs is the absolute value function.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int>indices;
        for(int i=0;i<n;i++){
            if(s[i]==c){
                indices.push_back(i);
            }
        }
        vector<int>answer;
        for(int i=0;i<n;i++){
            int index = lower_bound(indices.begin(),indices.end(),i)-indices.begin();
            if(index==0){
                answer.push_back(abs(i-indices[index]));
            }
            else if(index==indices.size()){
                answer.push_back(abs(i-indices[index-1]));
            }
            else{
                int dis1 = abs(i-indices[index]);
                int dis2 = abs(i-indices[index-1]);
                answer.push_back(min(dis1,dis2));
            }
        }
        return answer;
    }
};
