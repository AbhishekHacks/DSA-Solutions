/*You are given an integer array nums.
A subsequence sub of nums with length x is called valid if it satisfies:

(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
Return the length of the longest valid subsequence of nums.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.*/

//Time Complexity -- O(n)

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int maximum = INT_MIN;
        //case-1
        //case-a
        int count1 = 0;
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){
                count1++;
            }
        }
        maximum = max(maximum,count1);
        //case-b
        int count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                count2++;
            }
        }
        maximum = max(maximum,count2);

        //case-2
        int count3=1;
        int a;
        if(nums[0]%2==0){
            a=0;
        }
        else{
            a=1;
        }
        for(int i=1;i<n;i++){
            if(a==0){
                if(nums[i]%2!=0){
                    count3++;
                    a=1;
                }
            }
            else if(a==1){
                if(nums[i]%2==0){
                    count3++;
                    a=0;
                }
            }
        }
        return max(maximum,count3);
    }
};
