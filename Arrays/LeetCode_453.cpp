/*Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment n - 1 elements of the array by 1.

*/

//Time Complexity -- O(NlogN)

class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=nums.size()-1;
        int ans=0;
        while(nums[0]!=nums[i]){
            int diff = nums[i]-nums[0];
            ans+=diff;
            nums[0]+=diff;
            i--;
            nums[i]+=ans;
        }
        return ans;
    }
};
