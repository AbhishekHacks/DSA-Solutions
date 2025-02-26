/*Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.*/

//Brute force approach--O(n4)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> tempo;
        if(nums.size()<4){
            return tempo;
        }
        for(int i=0;i<nums.size()-3;i++){
            for(int j=i+1;j<nums.size()-2;j++){
                for(int k=j+1;k<nums.size()-1;k++){
                    for(int l=k+1;l<nums.size();l++){
                        long long sum = (long long)nums[i]+nums[j]+nums[k]+nums[l];
                        if(sum==target){
                            vector<int> v;
                            v.push_back(nums[i]);
                            v.push_back(nums[j]);
                            v.push_back(nums[k]);
                            v.push_back(nums[l]);
                            tempo.push_back(v);
                        }
                    }
                }
            }
        }
        for(int i=0;i<tempo.size();i++){
            sort(tempo[i].begin(),tempo[i].end());
        }
        set<vector<int>> s;
        for(int i=0;i<tempo.size();i++){
            s.insert(tempo[i]);
        }
        vector<vector<int>> answer;
        for(auto i:s){
            answer.push_back(i);
        }
        return answer;
    }
};
