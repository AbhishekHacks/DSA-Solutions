/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.*/

//Brute Force approach -- O(n^3)

//Note : This code won't get accepted because of its complexity

class Solution {
public:

    bool isPresent(vector<vector<int>> ans,vector<int> answer){
        for(int i=0;i<ans.size();i++){
            if(answer[0]==ans[i][0]&&answer[1]==ans[i][1]&&answer[2]==ans[i][2]){
                return 1;
            }
        }
        return 0;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        //Brute Force
        vector<vector<int>> answer;
        vector<int> v;
        
        //made a vector of vectors 
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        answer.push_back(v);
                        v.erase(v.begin(),v.end());
                    }
                }
            }
        }

        //check if the vector of vectors is empty
        if(answer.size()==0){
            return answer;
        }
        
        //sort the vectors
        for(int i=0;i<answer.size();i++){
            sort(answer[i].begin(),answer[i].end());
        }

        //remove the duplicates
        vector<vector<int>> ans;
        ans.push_back(answer[0]);
        for(int i=1;i<answer.size();i++){
            if(isPresent(ans,answer[i])==0){
                ans.push_back(answer[i]);
            }
        }
        return ans; 
    }
};
