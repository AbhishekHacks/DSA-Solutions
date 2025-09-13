/*You are given an integer array nums.

Return the smallest absent positive integer in nums such that it is strictly greater than the average of all elements in nums.

The average of an array is defined as the sum of all its elements divided by the number of elements.*/

//Time Complexity -- O(n)

class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        double sum = accumulate(nums.begin(),nums.end(),0.0);
        double avg = sum/n;
        int ans;
        for(int i=1;i<=101;i++){
            if(i>avg&&!m.count(i)){
                ans=i;
                break;
            }
        }
        return ans;
    }
};
