/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.*/

//This is not the most optimal approach but better than the naive O(n^3)

//Note : this code will get accepted but still it is not optimal

//Time Complexity -- O(n^2logn)

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        //Optimisation -- O(n^2logn)

        
        sort(nums.begin(),nums.end());
        vector<vector<int>> temporary;
        vector<int> v;

        int onlyzeros=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                onlyzeros=0;
                break;
            }
        }
        if(onlyzeros==1){
            v.push_back(0);
            v.push_back(0);
            v.push_back(0);
            temporary.push_back(v);
            return temporary;
        }
        
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                int key = -(nums[i]+nums[j]);
                int start=j+1;
                int end=nums.size()-1;
                while(start<=end){
                    int mid = start+(end-start)/2;
                    if(nums[mid]==key){
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(key);
                        temporary.push_back(v);
                        v.clear();
                        break;
                    }
                    else if(nums[mid]>key){
                        end = mid-1;
                    }
                    else{
                        start=mid+1;
                    }
                }
            }
        }

        //sort each vector inside temporary
        for(int i=0;i<temporary.size();i++){
            sort(temporary[i].begin(),temporary[i].end());
        }

        //keep the vectors of temporary in the set to remove duplicates
        set<vector<int>> s;
        for(int i=0;i<temporary.size();i++){
            s.insert(temporary[i]);
        }

        //finally push the unique triplets to another vector of vectors and return it
        vector<vector<int>> answer;
        for(auto i:s){
            answer.push_back(i);
        }

        return answer;
    }
};
