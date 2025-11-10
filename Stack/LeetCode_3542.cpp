/*You are given an array nums of size n, consisting of non-negative integers. Your task is to apply some (possibly zero) operations on the array so that all elements become 0.

In one operation, you can select a subarray [i, j] (where 0 <= i <= j < n) and set all occurrences of the minimum non-negative integer in that subarray to 0.

Return the minimum number of operations required to make all elements in the array 0.*//

//Time Complexity -- O(n)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        int count = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                while(!st.empty()){
                    st.pop();
                }
                continue;
            }
            while(!st.empty()&&nums[i]<st.top()){
                st.pop();
            }
            if(st.empty()||nums[i]>st.top()){
                st.push(nums[i]);
                count++;
            }
        }
        return count;
    }
};
