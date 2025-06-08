/*You are given an integer array nums of size n containing only 1 and -1, and an integer k.

You can perform the following operation at most k times:

Choose an index i (0 <= i < n - 1), and multiply both nums[i] and nums[i + 1] by -1.

Note that you can choose the same index i more than once in different operations.

Return true if it is possible to make all elements of the array equal after at most k operations, and false otherwise.*/

//Time Complexity -- O(n)

class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        int m=k;
        vector<int>temp(nums);
        //make all elements equal to -1
        int i=0;
        while(i<n-1&&k>0){
            if(nums[i]==1){
                nums[i]=-1;
                nums[i+1]=(nums[i+1]*-1);
                k--;
            }
            i++;
        }
        bool equal=true;
        for(int j=0;j<n-1;j++){
            if(nums[j]!=nums[j+1]){
                equal=false;
                break;
            }
        }
        if(equal){
            return true;
        }
        //make all elements equal to 1
        int l=0;
        while(l<n-1&&m>0){
            if(temp[l]==-1){
                temp[l]=1;
                temp[l+1]=(temp[l+1]*-1);
                m--;
            }
            l++;
        }
        bool nextequal=true;
        for(int j=0;j<n-1;j++){
            if(temp[j]!=temp[j+1]){
                nextequal=false;
                break;
            }
        }
        if(nextequal){
            return true;
        }
        return false;
    }
};
