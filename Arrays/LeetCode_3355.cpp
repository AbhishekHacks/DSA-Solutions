/*You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].

For each queries[i]:

Select a subset of indices within the range [li, ri] in nums.
Decrement the values at the selected indices by 1.
A Zero Array is an array where all elements are equal to 0.

Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.*/

//Time Complexity -- O(n+q)

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        vector<int>difference(n,0);
        for(int i=0;i<q;i++){
            int first_index = queries[i][0];
            int second_index = queries[i][1]+1;
            difference[first_index]+=1;
            if(second_index<n){
                difference[second_index]-=1;
            }
        }
        vector<int>prefix;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=difference[i];
            prefix.push_back(sum);
        }
        for(int i=0;i<n;i++){
            if(prefix[i]<nums[i]){
                return false;
            }
        }
        return true;
    }
};
