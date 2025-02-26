/*Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0*/

//Brute Force approach -- O(n4)

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        //Brute Force approach -- O(n4)
        int count=0;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                for(int k=0;k<nums3.size();k++){
                    for(int l=0;l<nums4.size();l++){
                        if(nums1[i]+nums2[j]+nums3[k]+nums4[l]==0){
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};
