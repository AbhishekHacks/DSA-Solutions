/*Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

*/

//Time Complexity -- O(n)

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        //count the number of characters in the array
        int n = s.size();

        //take two pointers i and j
        int i=0;
        int j=n-1;

        //run a loop and swap the characters in the place i and j
        while(i<j){
            swap(s[i],s[j]);

            //increment i and decrement j by 1
            i++;
            j--;
        }

        //note -- since the fucntion return type is void , you dont need to return anything
    }
};
