/*Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int> v;
        for(int i=1;i<=nums.size();i++){
            if(!m.count(i)){
                v.push_back(i);
            }
        }
        return v;
    }
};
