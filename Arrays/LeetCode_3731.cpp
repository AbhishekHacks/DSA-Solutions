/*You are given an integer array nums consisting of unique integers.

Originally, nums contained every integer within a certain range. However, some integers might have gone missing from the array.

The smallest and largest integers of the original range are still present in nums.

Return a sorted list of all the missing integers in this range. If no integers are missing, return an empty list.*//

//Time Complexity -- O(n)

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        auto smallest_it = min_element(nums.begin(),nums.end());
        auto largest_it = max_element(nums.begin(),nums.end());
        int smallest = *smallest_it;
        int largest = *largest_it;
        vector<int>ans;
        for(int i=smallest;i<=largest;i++){
            if(!m.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
