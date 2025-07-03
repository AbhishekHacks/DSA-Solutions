/*You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

 */

//Time Complexity -- O(nlogn)

class Solution {
public:

    long long modexpo(int base,int power){
        long long ans=1;
        while(power>0){
            if(power%2==0){
                base=((long long)base*base)%1000000007;
                power/=2;
            }
            else{
                ans=(ans*base)%1000000007;
                power--;
            }
        }
        return ans%1000000007;
    }

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long answer=0;
        for(int i=0;i<n;i++){
            int maximum = target - nums[i];
            int index = upper_bound(nums.begin(),nums.end(),maximum)-nums.begin();
            index-=1;
            index-=i;
            if(index<0){
                break;
            }
            answer=(answer+modexpo(2,index))%1000000007;
        }
        return answer%1000000007;
    }
};
