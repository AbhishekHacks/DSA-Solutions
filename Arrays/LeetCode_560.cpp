/*Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.*/

//Time Complexity -- O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //optimise  -- O(n)
        //prefix sum
        int n = nums.size();
        vector<int>prefix;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefix.push_back(sum);
        }
        unordered_map<int,int>m;
        int count=0;
        for(int i=0;i<n;i++){
            if(prefix[i]==k){
                count+=1;
                if(m.count(0)){
                    count+=m[0];
                }
            }
            else{
                int diff = prefix[i]-k;
                if(m.count(diff)){
                    count+=m[diff];
                }
            }
            m[prefix[i]]++;
        }
        return count;
    }
};
