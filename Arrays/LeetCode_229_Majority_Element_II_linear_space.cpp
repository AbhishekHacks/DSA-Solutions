/*Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //Time Complexity -- O(nlogn)
        int n=nums.size();
        vector<int>v;
        sort(nums.begin(),nums.end());
        int value = n/3;
        int count=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                count++;
            }
            else{
                if(count>value){
                    v.push_back(nums[i-1]);
                }
                count=1;
            }
        }
        if(count>value){
            v.push_back(nums[n-1]);
        }
        return v;
    }
};
