/*Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.*/

//Time Complexity -- O(N*Sqrt(M))

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
        for(int i=0;i<n;i++){
            int element = nums[i];
            int sum = 0;
            int count = 0;
            for(int j=1;j<=sqrt(element);j++){
                if(element%j==0){
                    if(j==(element/j)){
                        sum+=j;
                        count++;
                    }
                    else{
                        sum+=(j+(element/j));
                        count+=2;
                    }
                }
            }
            if(count==4){
                answer+=sum;
            }
        }
        return answer;
    }
};
