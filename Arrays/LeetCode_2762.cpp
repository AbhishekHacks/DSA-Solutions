/*You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:

Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.
Return the total number of continuous subarrays.

A subarray is a contiguous non-empty sequence of elements within an array.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) { //-- O(nlogn)
        int n = nums.size();
        map<int,int>m;
        int i=0,j=0;
        long long count=0;
        bool accepted = true;
        while(j<n){ //O(nlogn)
            if(accepted){
                m[nums[j]]++; //logn
            }
            auto it1 = m.begin();
            auto it2 = m.end();
            it2--;
            int maximum = it2->first;
            int minimum = it1->first;
            if((maximum-minimum)>=0&&(maximum-minimum)<=2){
                j++;
                accepted=true;
            }
            else{
                count+=(j-i);
                m[nums[i]]--;
                if(m[nums[i]]==0){
                    m.erase(nums[i]);
                }
                i++;
                accepted=false;
            }
        }
        long long rem = 0;
        for(auto p:m){ //O(n)
            rem+=p.second;
        }
        count+=(rem*(rem+1))/2;
        return count;
    }
};
