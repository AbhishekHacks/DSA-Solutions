/*You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.*/

//Time Complexity -- O(n)

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<char>s1;
        stack<int>s2;
        s1.push(s[0]);
        s2.push(1);
        int i=1;
        while(i<n){
            if(s1.size()==0){
                s1.push(s[i]);
                s2.push(1);
                i++;
            }
            else if(s[i]==s1.top()){
                int count = s2.top()+1;
                s1.push(s[i]);
                s2.push(count);
                i++;
            }
            else{
                if(s2.top()>=k){
                    for(int j=1;j<=k;j++){
                        s1.pop();
                        s2.pop();
                    }
                }
                else{
                    s1.push(s[i]);
                    s2.push(1);
                    i++;
                }
            }
        }
        if(s2.top()>=k){
            for(int j=1;j<=k;j++){
                s1.pop();
                s2.pop();
            }
        }
        string ans;
        if(s1.size()==0){
            return ans;
        }
        while(!s1.empty()){
            ans.push_back(s1.top());
            s1.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
