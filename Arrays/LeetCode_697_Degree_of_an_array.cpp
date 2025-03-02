/*Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.*/

//Time Complexity -- O(n2) (not optimal but gets accepted)

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n=nums.size();
        int max=-1;
        int length=-1;
        int index=-1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=i;j<n;j++){
                if(nums[i]==nums[j]){
                    count++;
                    index=j;
                }
            }
            if(max<count){
                max=count;
                length=index-i;
            }
            else if(max==count){
                if(length>(index-i)){
                    length=index-i;
                }
            }
        }
        return length+1;
    }
};
