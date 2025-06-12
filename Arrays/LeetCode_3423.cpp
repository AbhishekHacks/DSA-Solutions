/*Given a circular array nums, find the maximum absolute difference between adjacent elements.

Note: In a circular array, the first and last elements are adjacent.*/

//Time Complexity -- O(n)

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maximum = abs(nums[0]-nums[nums.size()-1]);
        for(int i=0;i<nums.size()-1;i++){
            int diff = abs(nums[i]-nums[i+1]);
            maximum = max(maximum,diff);
        }
        return maximum;
    }
};
