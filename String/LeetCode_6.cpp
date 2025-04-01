/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
*/

//Time Complexity -- O(N^2)

//Brute force approach -- Please do not prefer this solution as the calculations used here are too complex :(

class Solution {
public:
    string convert(string s, int numRows) {
        
        int rows = (numRows-1)/2;
        int n = s.size();

        if(numRows==1){
            return s; //single string , return the string itself
        }

        //output string
        string output;

        //logic its a pattern : just like zig zag

        //the outer loop signifies the number of rows
        for(int i=0;i<numRows;i++){

            //for every i there must be a j starting from i and than following a pattern
            int j=i;
            int prev=j;
            int count=0; // count will say what pattern for even and what for odd
            
            //the j must foolow the pattern until it becomes equal or greate than the string length
            while(j<n){

                //also the pattern is same for i=0 to rows and than different for rest
                if(i==0){
                    output.push_back(s[j]);
                    j=prev+((2*numRows)-2);
                    prev=j;
                }
                else if(i>0&&i<=rows){
                    output.push_back(s[j]);
                    if(count%2==0){
                        j=prev+((2*numRows)-(2*(i+1)));
                    }
                    else{
                        j=prev+(2*i);
                    }
                    prev=j;
                    count++;
                }
                else{
                    if(i==numRows-1){
                        output.push_back(s[j]);
                        j=prev+((2*numRows)-2);
                        prev=j;
                    }
                    else if(numRows%2==0){
                        output.push_back(s[j]);
                        if(count%2==0){
                            j=prev+(2*rows);
                        }
                        else{
                            j=prev+((2*numRows)-(2*(rows+1)));
                        }
                        prev=j;
                        count++;
                    }
                    else{
                        output.push_back(s[j]);
                        if(count%2==0){
                            j=prev+(2*(rows-1));
                        }
                        else{
                            j=prev+((2*numRows)-(2*rows));
                        }
                        prev=j;
                        count++;
                    }
                }
            }
            if(i>rows){
                rows--;
            }
        } 

        //return the output string
        return output;       
    }
};
