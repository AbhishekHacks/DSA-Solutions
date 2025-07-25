/*You are given an integer array nums.

You are allowed to delete any number of elements from nums without making it empty. After performing the deletions, select a subarray of nums such that:

All elements in the subarray are unique.
The sum of the elements in the subarray is maximized.
Return the maximum sum of such a subarray.*/

//Time Complexity -- O(n)

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        int maximum = INT_MIN;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            maximum = max(maximum,nums[i]);
        }
        int sum = 0;
        if(maximum<0){
            return maximum;
        }
        for(auto i:m){
            if(i.first>=0){
                sum+=i.first;
            }
        }
        return sum;
    }
};
