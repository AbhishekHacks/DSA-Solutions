/*You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.*/

//Time Complexity -- O(N)

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int distinct = m.size();
        int count=0;
        int left=0;
        unordered_map<int,int>temp;
        for(int i=0;i<n;i++){
            temp[nums[i]]++;
            if(temp.size()==distinct){
                int c = (n-i);
                count+=c;
                while(temp.size()==distinct){
                    temp[nums[left]]--;
                    if(temp[nums[left]]==0){
                        temp.erase(nums[left]);
                        left++;
                        break;
                    }
                    count+=c;
                    left++;
                }
            }
        }
        return count;
    }
};
