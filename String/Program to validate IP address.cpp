/*You are given the text ‘IPAddress’. Your task is to check if the given text ‘IPAddress’ is a valid ‘IPv4’ or not.

Conditions for a valid ‘IPv4’ are:

1. Text form of ‘IPAddress’ must be ‘a.b.c.d’
2. The values of a,b,c and d can vary from ‘0’ to ‘255’ and both ‘0’ and ‘255’ are inclusive.*/

//Time Complexity -- O(N)

#include <bits/stdc++.h> 
bool isValidIPv4(string ipAddress) {
    // Write your code here.
    int n = ipAddress.size();
    string temp;
    int countdot=0;
    for(int i=0;i<n;i++){
        if(ipAddress[i]!='.'&&(ipAddress[i]<'0'||ipAddress[i]>'9')){
            return false;
        }
        if(ipAddress[i]=='.'){
            if(temp.size()==0){
                return false;
            }
            int number = stoi(temp);
            if(number>255){
                return false;
            }
            temp.clear();
            countdot+=1;
        }
        else{
            temp.push_back(ipAddress[i]);
        }
    }
    int number = stoi(temp);
    if(number>255){
        return false;
    }
    if(countdot!=3){
        return false;
    }
    return true;
}
