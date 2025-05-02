/*You are given a string 'str' of length 'N'.



Your task is to reverse the original string word by word.



There can be multiple spaces between two words and there can be leading or trailing spaces but in the output reversed string you need to put a single space between two words, and your reversed string should not contain leading or trailing spaces.



Example :
If the given input string is "Welcome to Coding Ninjas", then you should return "Ninjas Coding to Welcome" as the reversed string has only a single space between two words and there is no leading or trailing space.*/

//Time Complexity -- O(n^2)

string reverseString(string &str){
	// Write your code here.
	int n = str.size();
	vector<string>v;
	string temp;
	int first_index;
	for(int i=0;i<n;i++){
		if(str[i]!=' '){
			first_index=i;
			break;
		}
	}
	int second_index;
	for(int i=n-1;i>=0;i--){
		if(str[i]!=' '){
			second_index=i;
			break;
		}
	}
	for(int i=first_index;i<=second_index;i++){
		if(str[i]!=' '){
			temp.push_back(str[i]);
		}
		else{
			if(str[i-1]==' '){
				continue;
			}
			v.push_back(temp);
			temp.clear();
		}
	}
	v.push_back(temp);
	string output;
	for(int i=v.size()-1;i>=0;i--){
		output.append(v[i]);
		output.push_back(' ');
	}

	return output;
}
