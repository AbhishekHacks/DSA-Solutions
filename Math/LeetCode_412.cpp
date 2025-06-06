/*Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.
*/

//Time Complexity -- O(n)

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>result;
        for(int i=1;i<=n;i++){
            if(i%3==0&&i%5==0){
                result.push_back("FizzBuzz");
            }
            else if(i%3==0){
                result.push_back("Fizz");
            }
            else if(i%5==0){
                result.push_back("Buzz");
            }
            else{
                string s=to_string(i);
                result.push_back(s);
            }
        }
        return result;
    }
};
