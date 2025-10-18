/*You are given a 0-indexed integer array nums and an integer value.

In one operation, you can add or subtract value from any element of nums.

For example, if nums = [1,2,3] and value = 2, you can choose to subtract value from nums[0] to make nums = [-1,2,3].
The MEX (minimum excluded) of an array is the smallest missing non-negative integer in it.

For example, the MEX of [-1,2,3] is 0 while the MEX of [1,0,3] is 2.
Return the maximum MEX of nums after applying the mentioned operation any number of times.*/

//Time Complexity -- O(n)

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int r = nums[i]%value;
            if(r<0){
                r+=value;
            }
            m[r]++;
        }
        int ans;
        for(int i=0;i<=n;i++){
            int r = i%value;
            if(m.count(r)){
                m[r]--;
                if(m[r]==0){
                    m.erase(r);
                }
            }
            else{
                ans=i;
                break;
            }
        }
        return ans;
    }
};
