/*Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.*/

//Time Complexity -- O(n^2logn)

class Solution {
public:
    int triangleNumber(vector<int>& nums) { 
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int sum = nums[i]+nums[j];
                int index = lower_bound(nums.begin()+j+1,nums.end(),sum)-nums.begin();
                count+=(index-1-j);
            }
        }
        if(count<0){
            count=0;
        }
        return count;
    }
};
