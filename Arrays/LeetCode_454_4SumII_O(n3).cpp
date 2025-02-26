/*Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0*/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        //better approach -- O(n3)
        sort(nums3.begin(),nums3.end());
        sort(nums4.begin(),nums4.end());
        int n=nums1.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int left = 0;
                int right = n-1;
                int sum = nums1[i]+nums2[j];
                int key = -sum;
                while(left<n&&right>=0){
                    int temp= nums3[left]+nums4[right];
                    if(temp==key){
                        int leftCount=1;
                        int rightCount=1;
                        while(left+1<n && nums3[left]==nums3[left+1]){
                            leftCount++;
                            left++;
                        }
                        while(right-1>=0 && nums4[right]==nums4[right-1]){
                            rightCount++;
                            right--;
                        }
                        count+=(leftCount*rightCount);
                        left++;
                        right--;
                    }
                    else if(temp>key){
                        right--;
                    }
                    else{
                        left++;
                    }
                }
            }
        }
        return count;
    }
};
