/*You are given a binary matrix with ‘M’ rows and ‘N’ columns initially consisting of all 0s. 'Q' queries follow. The queries can be of 4 types:

Query 1: 1 R index
Query 2: 1 C index 
Query 3: 2 R index
Query 4: 2 C index

In each query, the first input is the type of the query, the second input is whether we have to consider the row ('R') or the column ('C') and the third input is the index of the row/column. 

For each type 1 query, we need to flip the elements of the row/column having the given index. 

For each type 2 query, we have to output the number of zeros present in the row/column having the given index. */

//Time Complexity -- O(n^3)

#include<bits/stdc++.h>

void flip(vector<vector<int> > &mat, int m, int n,char rowcol,char index){
	int ind = index-'0';
	if(rowcol=='R'){
		for(int col = 0;col<n;col++){
			if(mat[ind][col]==0){
				mat[ind][col]=1;
			}
			else{
				mat[ind][col]=0;
			}
		}
	}
	else{
		for(int row=0;row<m;row++){
			if(mat[row][ind]==0){
				mat[row][ind]=1;
			}
			else{
				mat[row][ind]=0;
			}
		}
	}
}

int countzero(vector<vector<int> > &mat, int m, int n,char rowcol,char index){
	int ind = index-'0';
	int count=0;
	if(rowcol=='R'){
		for(int col=0;col<n;col++){
			if(mat[ind][col]==0){
				count+=1;
			}
		}
	}
	else{
		for(int row=0;row<m;row++){
			if(mat[row][ind]==0){
				count+=1;
			}
		}
	}
	return count;
}


vector<int> query(vector<vector<int> > &mat, int m, int n, vector<string> &q){
	// Write your code here.
	
	vector<int>output;
	int s = q.size();

	for(int i=0;i<s;i++){
		char type = q[i][0];
		char rowcol = q[i][1];
		char index = q[i][2];
		if(type=='1'){
			flip(mat,m,n,rowcol,index);
		}
		else{
			output.push_back(countzero(mat,m,n,rowcol,index));
		}
	}

	return output;
}
