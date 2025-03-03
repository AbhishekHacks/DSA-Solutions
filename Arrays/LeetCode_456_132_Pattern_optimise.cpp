/*Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //optimise -- O(n2)
        int n=nums.size();
        int j=1;
        while(j<n-1){
            int second=nums[j];
            set<int>s1;
            for(int i=0;i<j;i++){
                s1.insert(nums[i]);
            }
            set<int>s2;
            for(int i=j+1;i<n;i++){
                s2.insert(nums[i]);
            }
            int third = INT_MIN;
            for(auto i:s2){
                if(second>i){
                    third=i;
                }
            }
            if(third!=INT_MIN){
                auto it = s1.begin();
                int first = *it;
                if(third>first){
                    return true;
                }
            }
            j++;
        }
        return false;
    }
};
