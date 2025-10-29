/*You are given an integer array nums. You may rearrange the elements in any order.

The alternating score of an array arr is defined as:

score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 + ...
Return an integer denoting the maximum possible alternating score of nums after rearranging its elements.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        long long ans=0;
        int i=0,j=n-1;
        int count=0;
        while(i<=j){
            if(count%2==0){
                ans+=pow(nums[j],2);
                j--;
            }
            else{
                ans-=pow(nums[i],2);
                i++;
            }
            count++;
        }
        return ans;
    }
};
