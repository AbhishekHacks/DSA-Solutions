/*You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.

Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.*/

//Time Complexity -- O(nlogn)

class Solution {
public:

    bool isPossible(vector<int>& nums, int n, int p, int mid){
        int totalpairs=0;
        for(int i=0;i<n-1;i++){
            if(abs(nums[i]-nums[i+1])<=mid){
                totalpairs+=1;
                if(totalpairs>=p){
                    return true;
                }
                i++;
            }
        }
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        if(p==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int maximum = INT_MIN;
        int minimum = INT_MAX;
        for(int i=0;i<n;i++){
            maximum = max(maximum,nums[i]);
            minimum = min(minimum,nums[i]);
        }
        int start=0;
        int end=maximum-minimum;
        int answer=0;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(nums,n,p,mid)){
                answer=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return answer;
    }
};
