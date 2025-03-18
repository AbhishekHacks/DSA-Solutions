/*Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]
*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        vector<vector<int>>v;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            vector<int>vec;
            vec.push_back(i.first);
            vec.push_back(i.second);
            v.push_back(vec);
        }
        sort(v.begin(),v.end(),[](const vector<int>&a, vector<int>&b){
            return a[1]<b[1];
        });
        int n=v.size();
        for(int i=n-1;i>n-1-k;i--){
            ans.push_back(v[i][0]);
        }
        return ans;
    }
};
