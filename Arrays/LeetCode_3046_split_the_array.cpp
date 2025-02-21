/*You are given an integer array nums of even length. You have to split the array into two parts nums1 and nums2 such that:

nums1.length == nums2.length == nums.length / 2.
nums1 should contain distinct elements.
nums2 should also contain distinct elements.
Return true if it is possible to split the array, and false otherwise.*/

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            if(map.count(nums[i])==0){
                map[nums[i]]=1;
            }
            else{
                int value=map[nums[i]];
                if(value==2){
                    return 0;
                }
                map[nums[i]]=value+1;
            }
        }
        return 1;
    }
};
