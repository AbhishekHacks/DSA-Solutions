/*You are given an array nums of n integers and two integers k and x.

The x-sum of an array is calculated by the following procedure:

Count the occurrences of all elements in the array.
Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
Calculate the sum of the resulting array.
Note that if an array has less than x distinct elements, its x-sum is the sum of the array.

Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].*/

//Time Complexity -- O(N*K*log(K))

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int>answer;
        for(int i=0;i<n-k+1;i++){
            unordered_map<int,int>m;
            int sum = 0;
            for(int j=i;j<i+k;j++){
                m[nums[j]]++;
                sum+=nums[j];
            }
            if(m.size()<x){
                answer.push_back(sum);
            }
            else{
                vector<vector<int>>temp;
                for(auto it:m){
                    vector<int>t;
                    t.push_back(it.first);
                    t.push_back(it.second);
                    temp.push_back(t);
                }
                sort(temp.begin(),temp.end(),[](const vector<int>&a,vector<int>&b){
                    if(a[1]==b[1]){
                        return a[0]>b[0];
                    }
                    return a[1]>b[1];
                });
                int s = 0;
                for(int j=0;j<x;j++){
                    s+=(temp[j][0]*temp[j][1]);
                }
                answer.push_back(s);
            }
        }
        return answer;
    }
};
