/*You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:

Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
Return the lexicographically smallest string that can be written on the paper.*/

//Time Complexity -- O(N)

class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        string result;
        map<char,int>m;
        stack<char>st;
        for(int i=0;i<n;i++){
            m[s[i]]=i;
        }
        vector<char>arr1;
        vector<int>arr2;
        for(auto i:m){
            arr1.push_back(i.first);
            arr2.push_back(i.second);
        }
        int i=0;
        int j=0;
        while(i<n){
            while(i<=arr2[j]){
                if(s[i]==arr1[j]){
                    result.push_back(arr1[j]);
                }
                else{
                    st.push(s[i]);
                }
                i++;
            }
            j++;
            while(!st.empty()&&st.top()<=arr1[j]){
                result.push_back(st.top());
                st.pop();
            }
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};
