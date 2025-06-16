/*Given a string ‘STR’ consisting of lower case English letters, the task is to find the first non-repeating character in the string and return it. If it doesn’t exist, return ‘#’.

For example:

For the input string 'abcab', the first non-repeating character is ‘c’. As depicted the character ‘a’ repeats at index 3 and character ‘b’ repeats at index 4. Hence we return the character ‘c’ present at index 2.*/

//Time Complexity -- O(n)

#include <bits/stdc++.h> 
char findNonRepeating(string str) {
    // Write your code here.
    unordered_map<char,int>m;
    int n = str.size();
    for(int i=0;i<n;i++){
        m[str[i]]++;
    }
    for(int i=0;i<n;i++){
        if(m[str[i]]==1){
            return str[i];
        }
    }
    return '#';
}
