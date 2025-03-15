/*Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.*/

//Time Complexity -- O(n)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n,-1);
        stack<int>s;
        for(int i=2*n-1;i>=0;i--){
            while(!s.empty()&&s.top()<=nums[i%n]){
                s.pop();
            }
            if(!s.empty()){
                v[i%n]=s.top();
            }
            s.push(nums[i%n]);
        }
        return v;
    }
};
