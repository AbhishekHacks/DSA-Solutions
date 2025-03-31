/*You are given an array ‘STRINGS’ having ‘N’ number of strings. The strings are assumed to be arranged such that there is one string in one line.

You need to return the number of columns that are not sorted lexicographically.

Note:
The length of all the strings in the array is the same.
For Example:
If the given array is [ “bde”, “dcf”, “gat” ], then it can be assumed to arranged as
bde
dcf 
gat 

Now the ‘0-th’ column (‘b’, ‘d’, ‘e’) and ‘2-th’ column ( ‘e’, ‘f’, ‘t’ ) are lexicographically sorted but the ‘1-st’ column ( ‘d’, ‘c’, ‘a’ ) is not sorted lexicographically. So you need to return 1.*/

//Time Complexity -- O(n*length of string)

#include <bits/stdc++.h> 
int countColumns(vector<string> &strings)
{
    // Write your code here.

    int n = strings.size();

    /*logic -- take a pointer i , keep the pointer in the first character of every string in vector 
    and compare if the characters are sorted , once checked increment the pointer and do the same 
    while also counting how many times characters were unsorted*/
    int count=0;

    //i iterates from 0 to string length
    int length = strings[0].size();

    for(int i=0;i<length;i++){ // remember i is our pointer
        for(int j=0;j<n-1;j++){
            string s1=strings[j];
            string s2=strings[j+1];
            if(s1[i]>s2[i]){
                count+=1;
                break;
            }
        }
    }

    //return count
    return count;
}
