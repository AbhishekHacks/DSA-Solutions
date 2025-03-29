/*Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
*/

//Time Complexity -- O(N)

class Solution {
public:
    string reverseWords(string s) {
        
        int n=s.size();

        //take two strings one temporary and another output
        string temp="";
        string output="";

        for(char ch : s){

            //when you dont encounter any whitespace
            if(ch!=' '){
                
                //just add the characters in the variable temp
                temp.push_back(ch); 
            }

            //when you encounter space add word in temp in output string
            else{

                //first reverse the word in temp
                reverse(temp.begin(),temp.end());
                
                output+=temp+" ";
                temp="";
            }
        }

        //lastly take care of the last word
        reverse(temp.begin(),temp.end());
        output+=temp;

        //return the string
        return output;
    }
};
