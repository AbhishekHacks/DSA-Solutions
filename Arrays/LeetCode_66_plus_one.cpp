/*You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]==9&&carry==1){
                digits[i]=0;
                carry=1;
            }
            else if(digits[i]<9&&carry==1){
                digits[i]=digits[i]+1;
                return digits;
            }
            else{
                return digits;
            }
        }
        vector<int> answer;
        answer.push_back(1);
        for(int i=0;i<digits.size();i++){
            answer.push_back(digits[i]);
        }
        return answer;
    }
};
