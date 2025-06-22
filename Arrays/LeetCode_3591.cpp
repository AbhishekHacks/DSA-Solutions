/*You are given an integer array nums.

Return true if the frequency of any element of the array is prime, otherwise, return false.

The frequency of an element x is the number of times it occurs in the array.

A prime number is a natural number greater than 1 with only two factors, 1 and itself.*/

//Time Complexity -- O(nsqrt(n))

class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        for(auto i:freq){
            int num = i.second;
            if(num==1){
                continue;
            }
            bool prime = true;
            for(int i=2;i<=sqrt(num);i++){
                if(num%i==0){
                    prime=false;
                    break;
                }
            }
            if(prime){
                return true;
            }
        }
        return false;
    }
};
