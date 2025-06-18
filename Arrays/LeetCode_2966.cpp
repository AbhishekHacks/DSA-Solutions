/*You are given an integer array nums of size n where n is a multiple of 3 and a positive integer k.

Divide the array nums into n / 3 arrays of size 3 satisfying the following condition:

The difference between any two elements in one array is less than or equal to k.
Return a 2D array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>answer;
        vector<int>temp;
        for(int i=0;i<n;i++){
            temp.push_back(nums[i]);
            if((i+1)%3==0){
                answer.push_back(temp);
                temp.clear();
            }
        }
        int l = answer.size();
        bool ispossible = true;
        for(int i=0;i<l;i++){
            if(answer[i][2]-answer[i][0]>k){
                ispossible=false;
                break;
            }
        }
        if(!ispossible){
            answer.clear();
        }
        return answer;
    }
};
