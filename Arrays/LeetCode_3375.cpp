/*You are given an integer array nums and an integer k.

An integer h is called valid if all values in the array that are strictly greater than h are identical.

For example, if nums = [10, 8, 10, 8], a valid integer is h = 9 because all nums[i] > 9 are equal to 10, but 5 is not a valid integer.

You are allowed to perform the following operation on nums:

Select an integer h that is valid for the current values in nums.
For each index i where nums[i] > h, set nums[i] to h.
Return the minimum number of operations required to make every element in nums equal to k. If it is impossible to make all elements equal to k, return -1.

*/

//Time Complexity -- O(n)

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        unordered_map<int,int>m;
        int n = nums.size();

        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }

        int count=0;
        for(auto i:m){
            if(i.first<k){
                return -1;
            }
            else if(i.first>k){
                count+=1;
            }
        }

        return count;
    }
};
