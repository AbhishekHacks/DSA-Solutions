/*You are given a 0-indexed integer array nums and two integers key and k. A k-distant index is an index i of nums for which there exists at least one index j such that |i - j| <= k and nums[j] == key.

Return a list of all k-distant indices sorted in increasing order.*/

//Time Complexity -- O(n)

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int>indices;
        for(int i=0;i<n;i++){
            if(nums[i]==key){
                indices.push_back(i);
            }
        }
        int l = indices.size();
        vector<int>answer;
        int prev_end=-1;
        for(int i=0;i<l;i++){
            int begin = indices[i]-k;
            int end = indices[i]+k;
            if(begin<0){
                begin=0;
            }
            if(end>n-1){
                end=n-1;
            }
            if(begin<=prev_end){
                begin=prev_end+1;
            }
            for(int j=begin;j<=end;j++){
                answer.push_back(j);
            }
            prev_end=end;
        }
        return answer;
    }
};
