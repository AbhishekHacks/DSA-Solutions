/*Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.*/

//Time Complexity -- O(N)

class Solution {
public:
    int compress(vector<char>& chars) {
        
        int n=chars.size();

        //take a startingIndex
        int startIndex=0;

        //take a prev varaiable to store the previous character 
        char prev = chars[0];

        //count variable --  to count the occurrence
        int count=0;

        //iterate the vector
        for(int i=0;i<n;i++){

            //current character
            char curr = chars[i];

            //compare
            if(prev==curr){
                count++;
            }

            else{
                i--;
                if(count==1){
                    chars[startIndex++]=prev;
                }
                else if(count>1&&count<10){
                    chars[startIndex++]=prev;
                    chars[startIndex++]='0'+count;
                }
                else{
                    
                    chars[startIndex++]=prev;

                    //convert the count into string
                    string temp = to_string(count);

                    for(char ch:temp){
                        chars[startIndex++]=ch;
                    }
                }
                count=0;
            }

            //update prev with curr
            prev=curr;
        }

        //for the last character
        if(count==1){
            chars[startIndex++]=prev;
        }
        else if(count>1&&count<10){
            chars[startIndex++]=prev;
            chars[startIndex++]='0'+count;
        }
        else{
                    
            chars[startIndex++]=prev;

            //convert the count into string
            string temp = to_string(count);

            for(char ch : temp){
                chars[startIndex++]=ch;
            }
        }

        //return the length
        return startIndex;
    }
};
