/*Given an integer array nums and an integer k, return the number of good subarrays of nums.

A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].

A subarray is a contiguous non-empty sequence of elements within an array.*/

//Time Complexity -- O(n)

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long count=0,pairs=0;
        int i=0,j=0;
        unordered_map<int,int>m;
        bool i_increased = false;
        while(j<n){
            if(i_increased){
                int prev = m[nums[i-1]];
                m[nums[i-1]]--;
                pairs-=(prev*(prev-1))/2;
                pairs+=((prev-1)*(prev-2))/2;
                if(pairs>=k){
                    count+=(n-j);
                    i++;
                }
                else{
                    j++;
                    i_increased=false;
                }
            }
            else{
                if(m.count(nums[j])){
                    pairs+=m[nums[j]];
                    if(pairs>=k){
                        count+=(n-j);
                        i++;
                        i_increased = true;
                        m[nums[j]]++;
                    }
                    else{
                        m[nums[j]]++;
                        j++;
                    }
                }
                else{
                    m[nums[j]]++;
                    j++;
                }
            }
        }
        return count;
    }
};
