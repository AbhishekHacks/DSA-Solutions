/*Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 */

//Time Complexity -- O(n)

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        int minimum = INT_MAX;
        unordered_map<char,int>m;
        for(int i=0;i<n;i++){
            m[text[i]]++;
        }
        if(!m.count('b')||!m.count('a')||!m.count('l')||!m.count('o')||!m.count('n')){
            return 0;
        }
        minimum = min(minimum,m['b']);
        minimum = min(minimum,m['a']);
        minimum = min(minimum,(m['l']/2));
        minimum = min(minimum,(m['o']/2));
        minimum = min(minimum,m['n']);
        return minimum;
    }
};
