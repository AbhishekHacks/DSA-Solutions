/*Given a string s, partition it into unique segments according to the following procedure:

Start building a segment beginning at index 0.
Continue extending the current segment character by character until the current segment has not been seen before.
Once the segment is unique, add it to your list of segments, mark it as seen, and begin a new segment from the next index.
Repeat until you reach the end of s.
Return an array of strings segments, where segments[i] is the ith segment created.*/

//Time Complexity -- O(n)

class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string>ans;
        int n = s.size();
        unordered_map<string,int>m;
        string str;
        for(int i=0;i<n;i++){
            str.push_back(s[i]);
            if(m.count(str)==0){
                ans.push_back(str);
                m[str]++;
                str.clear();
            }
        }
        return ans;
    }
};
