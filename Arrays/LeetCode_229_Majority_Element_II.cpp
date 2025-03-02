/*Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.*/
//Time Complexity -- O(n)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int value = nums.size()/3;
        unordered_map<int,int> m;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            if(i.second>value){
                v.push_back(i.first);
            }
        }
        return v;
    }
};
