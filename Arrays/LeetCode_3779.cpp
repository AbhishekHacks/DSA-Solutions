/*You are given an integer array nums.

In one operation, you remove the first three elements of the current array. If there are fewer than three elements remaining, all remaining elements are removed.

Repeat this operation until the array is empty or contains no duplicate values.

Return an integer denoting the number of operations required.*/

//Time Complexity -- O(n)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        int maximum = -1;
        for(int i=0;i<n;i++){
            if(!m.count(nums[i])){
                m[nums[i]]=i;
            }
            else{
                maximum = max(maximum,m[nums[i]]);
                m[nums[i]]=i;
            }
        }
        if(maximum==-1){
            return 0;
        }
        return (maximum/3)+1;
    }
};
