/*You have been given a string 'STR' of words. You need to replace all the spaces between words with “@40”.*/

//Time Complexity -- O(length of string)

#include <bits/stdc++.h> 
string replaceSpaces(string &str){
	// Write your code here.

	int n=str.size();

	//iterate the string and where you find the white space replace it with '@40'
	string answer="";

	for(int i=0;i<n;i++){
		if(str[i]==' '){
			answer.push_back('@');
			answer.push_back('4');
			answer.push_back('0');
		}
		else{
			answer.push_back(str[i]);
		}
	}

	//return the answer 
	return answer;
}
