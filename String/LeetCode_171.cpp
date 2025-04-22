/*Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...*/

//Time Complexity -- O(n)

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int answer=0;

        int power=0;
        for(int i=n-1;i>=0;i--){
            answer+=((columnTitle[i]-'A'+1)*(int)pow(26,power));
            power++;
        }

        return answer;
    }
};
