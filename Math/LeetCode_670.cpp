/*You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.*/

//Time Complexity -- O(NlogN)

class Solution {
public:
    int maximumSwap(int num) {
        vector<int>number;
        int n = num;
        while(n>0){
            int r = n%10;
            number.push_back(r);
            n/=10;
        }
        reverse(number.begin(),number.end());
        vector<int>sortednumber(number);
        sort(sortednumber.begin(),sortednumber.end());
        reverse(sortednumber.begin(),sortednumber.end());
        unordered_map<int,int>m;
        for(int i=0;i<number.size();i++){
            m[number[i]]=i;
        }
        for(int i=0;i<number.size();i++){
            if(number[i]!=sortednumber[i]){
                int index = m[sortednumber[i]];
                swap(number[i],number[index]);
                break;
            }
        }
        int result=0;
        for(int i=0;i<number.size();i++){
            result=(result*10)+number[i];
        }
        return result;
    }
};
