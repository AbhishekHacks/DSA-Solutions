/*You are given an array of ‘N’ sentences. Each sentence is a space-delimited string of words. The first word in each sentence is an alphanumeric identifier. Then, at least one of the following conditions will hold true:

1. After identifier, each word will consist only of lowercase English letters
2. After the identifier, each word will consist only of numbers.
We will call these two types of sentences, letter – sentence and number– sentence. It is guaranteed that each sentence has at least one word after its identifier. Your task is to sort these sentences such that the following two conditions will hold.

1. All letter - sentences must come before number- sentences.
2. The letter - sentences must be ordered lexicographically ignoring identifiers. The identifier will be used in case of ties.
3. The number– sentence must be put in their original order of occurrence. */

//This solution is NOT RECOMMENDED

#include <bits/stdc++.h> 

string ignorefirstword(string s){
	stringstream ss(s);
	string word;
	ss>>word;
	string rest;
	getline(ss,rest);
	return rest;
}

string firstword(string s){
	stringstream ss(s);
	string first;
	ss>>first;
	return first;
}

bool compareignorefirstword(const string&a, const string&b){
	if(ignorefirstword(a)==ignorefirstword(b)){
		return firstword(a)<firstword(b);
	}
	return ignorefirstword(a)<ignorefirstword(b);
}

bool isNumberSentences(const string&s){
	stringstream ss(s);
	string word;
	ss>>word;
	while(ss>>word){
		for(char c:word){
			if(!isdigit(c)){
				return false;
			}
		}
	}
	return true;
}

vector<string> reOrderSentences(vector<string> sentences)
{
	// Write your code here

	int n = sentences.size();

	vector<string>letter_sentences;
	vector<string>number_sentences;
	vector<string>output;

	for(int i=0;i<n;i++){
		string s = sentences[i];
		if(isNumberSentences(s)){
			number_sentences.push_back(s);
		}
		else{
			letter_sentences.push_back(s);
		}
	}

	//sorting lexicographically
	sort(letter_sentences.begin(),letter_sentences.end(),compareignorefirstword);
	for(int i=0;i<letter_sentences.size();i++){
		output.push_back(letter_sentences[i]);
	}

	for(int i=0;i<number_sentences.size();i++){
		output.push_back(number_sentences[i]);
	}

	return output;
}
