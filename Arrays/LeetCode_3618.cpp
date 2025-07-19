/*You are given an integer array nums.

Split nums into two arrays A and B using the following rule:

Elements at prime indices in nums must go into array A.
All other elements must go into array B.
Return the absolute difference between the sums of the two arrays: |sum(A) - sum(B)|.

A prime number is a natural number greater than 1 with only two factors, 1 and itself.

Note: An empty array has a sum of 0.*/

//Time Complexity -- O(n^3/2)

class Solution {
public:

    bool isprime(int num){
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return abs((long long)nums[0]);
        }
        else if(n==2){
            return abs((long long)nums[0]+nums[1]);
        }
        long long suma = 0;
        long long sumb = nums[0]+nums[1];
        for(int i=2;i<n;i++){
            if(isprime(i)){
                suma+=nums[i];
            }
            else{
                sumb+=nums[i];
            }
        }
        return abs(suma-sumb);
    }
};
