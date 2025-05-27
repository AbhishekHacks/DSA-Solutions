/*You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.*/

//Time Complexity -- O(n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>output;
        int n = nums.size();
        map<int,int>m;
        for(int i=0;i<k;i++){
            m[nums[i]]++;
        }
        auto first_max = prev(m.end());
        output.push_back(first_max->first);
        for(int i=k;i<n;i++){
            m[nums[i-k]]--;
            if(m[nums[i-k]]==0){
                m.erase(nums[i-k]);
            }
            m[nums[i]]++;
            auto maximum = prev(m.end());
            output.push_back(maximum->first);
        }
        return output;
    }
};
