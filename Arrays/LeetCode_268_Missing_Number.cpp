/*Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //Optimised -- O(n)
        int n=nums.size();
        long long sum1=(n*(n+1))/2;
        long long sum2=0;
        int answer=0;
        for(int i=0;i<nums.size();i++){
            sum2+=nums[i];
        }
        answer=sum1-sum2;
        return answer;
    }
};
