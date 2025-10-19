/*You are given an integer array nums and an integer k.

You are allowed to perform the following operation on each element of the array at most once:

Add an integer in the range [-k, k] to the element.
Return the maximum possible number of distinct elements in nums after performing the operations.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int start = nums[i]-k;
            int end = nums[i]+k;
            int ans=INT_MIN;
            while(start<=end){
                int mid = start+(end-start)/2;
                if(!m.count(mid)){
                    ans=mid;
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            if(ans!=INT_MIN){
                m[ans]++;
            }
        }
        return m.size();
    }
};
