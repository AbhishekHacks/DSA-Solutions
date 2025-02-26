/*Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.*/

//Time Complexity -- O(n3) optimal

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //optimise -- O(n3)
        vector<vector<int>> answer;
        if(nums.size()<4){
            return answer;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<nums.size()-2;j++){
                long long sum = (long long)nums[i]+nums[j];
                long long key = target - sum;
                int left = j+1;
                int right = nums.size()-1;
                while(left<right){
                    long long sum = (long long)nums[left]+nums[right];
                    if(key==sum){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[left]);
                        v.push_back(nums[right]);
                        answer.push_back(v);
                        while(left<right&&nums[left]==nums[left+1]){
                            left++;
                        }
                        while(right>left&&nums[right]==nums[right-1]){
                            right--;
                        }
                        left++;
                        right--;
                    }
                    else if(sum<key){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
                while(j+1<left&&nums[j]==nums[j+1]){
                    j++;
                }
            }
        }
        return answer;
    }
};
