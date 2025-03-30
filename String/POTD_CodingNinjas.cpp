/*Ninja is shifting to a new place named NinjaGram. To take admission to the new school, the teacher gives him a sentence and asks him to check whether the sentence is a pangram.

A word or a sentence is called a pangram if it contains all the English alphabet letters.

Since Ninja is new to programming, he doesn’t have much experience; he asks you to solve the problem. Can you help Ninja figure out whether the sentence is a pangram?*/

//Time Complexity -- O(N)

#include <bits/stdc++.h> 
bool ninjaGram(string &str)
{
    // Write your code here

    int n = str.size();
    
    for(char ch = 'a';ch<='z';ch++){
        if(str.find(ch)==-1){
            if(str.find((char)(ch-32))==-1){
                return false;
            }
        }
    }

    return true;

}
