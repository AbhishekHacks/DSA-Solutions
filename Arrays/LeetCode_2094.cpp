/*You are given an integer array digits, where each element is a digit. The array may contain duplicates.

You need to find all the unique integers that follow the given requirements:

The integer consists of the concatenation of three elements from digits in any arbitrary order.
The integer does not have leading zeros.
The integer is even.
For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

Return a sorted array of the unique integers.*/

//Time Complexity --- O(n)

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int>output;
        for(int i=100;i<=999;i++){ 
            unordered_map<int,int>m;
            for(int i=0;i<n;i++){
                m[digits[i]]++;
            }
            if(i%2==0){ 
                int element = i;
                bool canbeformed = true;
                while(element>0){
                    int r = element%10;
                    if(m.count(r)){
                        if(m[r]>1){
                            m[r]--;
                        }
                        else{
                            m.erase(r);
                        }
                    }
                    else{
                        canbeformed=false;
                        break;
                    }
                    element/=10;
                }
                if(canbeformed){
                    output.push_back(i);
                }
            }
        }
        return output;
    }
};
