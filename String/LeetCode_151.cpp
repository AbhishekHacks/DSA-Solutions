/*Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

*/

//Time Complexity -- O(length of string)

class Solution {
public:
    string reverseWords(string s) {
        
        int n=s.size();

        //store the words in temp
        string temp="";

        //output string
        string str="";

        bool begin=true;

        //iterate the string
        for(int i=0;i<n;i++){

            //ignore the beginning spaces
            if(s[i]==' '&&begin==true){
                continue;
            }

            //store the characters in the temp string
            else if(s[i]!=' '){
                temp.push_back(s[i]);
                begin=false;
            }

            //if a word is completed stopre it in str string 
            else if(s[i]==' '){
                str=temp+' '+str;
                temp="";
                begin=true; //this will not include extra spaces between words
            }
        }
        
        //check if the ending of the string has a space
        if(s[n-1]!=' '){
            str=temp+' '+str;
        }

        //we have to remove the white space from the end in our output string
        int length = str.size();
        str[length-1]='\0';

        //take another output string -- answer
        string answer;

        //now put the characters of str in answer untill iterator encounters '\0'
        for(int i=0;str[i]!='\0';i++){
            answer.push_back(str[i]);
        }

        //return the answer string
        return answer;
    }
};
