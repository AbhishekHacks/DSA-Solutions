/*Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.*/

//Time Complexity -- O(n3logn)

//This runs but the solution is not the most optimal 

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //optimise -- O(n3logn)
        vector<vector<int>> tempo;
        if(nums.size()<4){
            return tempo;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            for(int j=i+1;j<nums.size()-2;j++){
                for(int k=j+1;k<nums.size()-1;k++){
                    long long sum = (long long)nums[i]+nums[j]+nums[k];
                    long long key = target - sum;
                    int start=k+1;
                    int end=nums.size()-1;
                    while(start<=end){
                        int mid = start+(end-start)/2;
                        if(nums[mid]==key){
                            vector<int> v;
                            v.push_back(nums[i]);
                            v.push_back(nums[j]);
                            v.push_back(nums[k]);
                            v.push_back(key);
                            tempo.push_back(v);
                            break;
                        }
                        else if(nums[mid]>key){
                            end=mid-1;
                        }
                        else{
                            start=mid+1;
                        }
                    }
                }
            }
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
