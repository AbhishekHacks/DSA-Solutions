/*Given a string s, return the longest palindromic substring in s.*/

//Time Complexity -- O()

class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();

        //logic -- for every character from second to n-2 try to expand across the character as far as you can , and if at certain point the substring cannot be expanded , store the length and compare if it greater than the highest length and than store it the output string
        string output;
        output.push_back(s[0]); //if highest is equal to 1 than the first character will be the longest palindromic substring
        int highest = 1;

        //odd length palindrome substring
        for(int i=1;i<n-1;i++){

            //for every character keep maintaining two pointers
            int prev_index=i-1;
            int next_index=i+1;

            //run another loop for expanding
            while(prev_index>=0&&next_index<=n-1){
                if(s[prev_index]==s[next_index]){
                    prev_index--;
                    next_index++;
                }
                else{
                    int length = (next_index-prev_index)-1;
                    if(highest<length){
                        highest=length;
                        output=s.substr(prev_index+1,length);
                    }
                    break;
                }
            }

            //if no break was there and we came out of loop because prev_index<0 or next_index>n-1 , compute the length once again
            int length = (next_index-prev_index)-1;
            if(highest<length){
                highest=length;
                output=s.substr(prev_index+1,length);
            }
        }

        //even length palindrome substring
        for(int i=0;i<n-1;i++){

            //same two pointers
            int prev_index=i;
            int next_index=i+1;
            
            //check if the next character is equal
            while(prev_index>=0&&next_index<=n-1){
                if(s[prev_index]==s[next_index]){
                    prev_index--;
                    next_index++;
                }
                else{
                    int length = (next_index-prev_index)-1;
                    if(highest<length){
                        highest=length;
                        output=s.substr(prev_index+1,length);
                    }
                    break;
                }
            }

            int length = (next_index-prev_index)-1;
            if(highest<length){
                highest=length;
                output=s.substr(prev_index+1,length);
            }
        }

        //return the string
        return output;
    }
};
