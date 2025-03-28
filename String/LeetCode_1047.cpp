/*You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

*/

//Time Complexity -- O(N)

class Solution {
public:
    string removeDuplicates(string s) {

        string st;

        for(char ch:s){
            if(!st.empty()&&st.back()==ch){
                st.pop_back();
            }
            else{
                st.push_back(ch);
            }
        }

        return st;
    }
};
