/*You are given an integer array nums.

Return the smallest index i such that the sum of the digits of nums[i] is equal to i.

If no such index exists, return -1.*/

//Time Complexity -- O(nlogm)

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int element = nums[i];
            int sum = 0;
            while(element>0){
                int r = element%10;
                sum+=r;
                element/=10;
            }
            if(sum==i){
                return i;
            }
        }
        return -1;
    }
};
