/*Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long count=0;
        for(int i=0;i<n-1;i++){
            int start=i+1;
            int end=n-1;
            int ptr1=-1;
            int ptr2=-1;
            while(start<=end){
                int mid = start+(end-start)/2;
                if(nums[i]+nums[mid]>=lower){
                    ptr1=mid;
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            start=i+1;
            end=n-1;
            while(start<=end){
                int mid = start+(end-start)/2;
                if(nums[i]+nums[mid]<=upper){
                    ptr2=mid;
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            if(ptr1!=-1&&ptr2!=-1&&ptr2-ptr1>=0){
                count += (ptr2-ptr1)+1;
            }
        }

        return count;
    }
};
