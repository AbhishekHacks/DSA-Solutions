/*Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.*/

//Time Complexity -- O(N*Sqrt(M))

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        //Brute Force approach 
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int element = nums[i];
            int count=2;
            int temp_sum=1+element;
            for(int j=2;j<=element/2;j++){
                if(element%j==0){
                    temp_sum+=j;
                    count++;
                    if(count>4){
                        break;
                    }
                }
            }
            if(count==4){
                sum+=temp_sum;
            }
        }
        return sum;
    }
};
