/*You are given a string, 'MESSAGE'. The receiver of this ‘MESSAGE’ has a set of instructions on how to decrypt the message. In order to decrypt the message, we need to perform some rotation operations on the string.

These rotations can either be left rotations or right rotations. The set of instructions contains information about which type of rotation is to be performed and how many times. Your task is to determine the decrypted message.

Note:

Performing a 'left rotation' means deleting the first character of the string and appending it to the end of the string.

Performing a 'right rotation' means deleting the last character of the string and appending it to the beginning of the string.

For example, if we perform a left rotation on the string “coding”, it will become “odingc”. If we perform a right rotation on the string “ninja”, it will become “aninj”.*/

//Time Complexity -- O(n*m)

#include <bits/stdc++.h> 

void reverse(string& message,int i,int j){
	while(i<j){
		char temp = message[i];
		message[i] = message[j];
		message[j] = temp;
		i++;
		j--;
	}
}

string decrypt(string& message, vector<vector<int>>& operations) {
	// Write your code here.
	int n = operations.size();
	int len = message.size();
	for(int i=0;i<n;i++){
		if(operations[i][0]==-1){
			reverse(message,0,(operations[i][1]%len)-1);
			reverse(message,(operations[i][1]%len),len-1);
			reverse(message,0,len-1);
		}
		else{
			reverse(message,0,len-(operations[i][1]%len)-1);
			reverse(message,len-(operations[i][1]%len),len-1);
			reverse(message,0,len-1);
		}
	}
	return message;
}
