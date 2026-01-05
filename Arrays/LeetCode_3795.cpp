/*You are given an integer array nums and an integer k.

Return the minimum length of a subarray whose sum of the distinct values present in that subarray (each value counted once) is at least k. If no such subarray exists, return -1.*/

//Time Complexity -- O(nlogn)

class Solution {
public:

    bool isPossible(vector<int>nums,int n,int k,int mid){
        unordered_map<int,int>m;
        long long sum = 0;
        for(int i=0;i<mid;i++){
            if(!m.count(nums[i])){
                sum+=nums[i];
            }
            m[nums[i]]++;
        }
        if(sum>=k){
            return true;
        }
        int index = 0;
        for(int i=mid;i<n;i++){
            m[nums[index]]--;
            if(m[nums[index]]==0){
                sum-=nums[index];
                m.erase(nums[index]);
            }
            if(!m.count(nums[i])){
                sum+=nums[i];
                if(sum>=k){
                    return true;
                }
            }
            m[nums[i]]++;
            index++;
        }
        return false;
    }
    
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 1;
        int end = n;
        int answer = -1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(nums,n,k,mid)){
                answer = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return answer;
    }
};
