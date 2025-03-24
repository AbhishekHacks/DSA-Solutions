/*Problem statement
Ninjas are trying to hack a system of a terrorist organization so that they can know where they will be going to attack next. But to hack the system and to get access to data they need a password that must satisfy certain conditions as described below:

1) Length of the password must be between 8 to 15 characters.
2) At least one digit (0-9), one lowercase letter (a-z), one uppercase letter (A-Z) and one special character (%, ^, &, #, *, %, etc) must be present.
3) Password must not contain any space.
You are given a string ‘STR’, help ninjas to find whether it's a valid password or not.

For example :

Given ‘STR’ =  “Codingninja#1” As it satisfies all the above conditions so it is a valid password and therefore you have to return true.*/

//Time Complexity -- O(length of string)

bool isValid(string &str) {
	// Write your code here.

	int n=str.length();

	//check if the length of string is between 8 to 15 characters
	if(n<8||n>15){
		return false;
	}

	//check if the string contain a lower case , uppercase , digit and spcial character
	int d=0;
	int cap=0;
	int sma=0;
	int spec=0;
	for(int i=0;i<n;i++){
		if(str[i]>='0'&&str[i]<='9'){
			d++;
		}
		else if(str[i]>='A'&&str[i]<='Z'){
			cap++;
		}
		else if(str[i]>='a'&&str[i]<='z'){
			sma++;
		}
		else if(str[i]==' '){
			return false;
		}
		else{
			spec++;
		}
	}

	//check if all conditions were fulfilled
	if(d>=1&&cap>=1&&sma>=1&&spec>=1){
		return true;
	}

	//if not return false
	return false;
}
