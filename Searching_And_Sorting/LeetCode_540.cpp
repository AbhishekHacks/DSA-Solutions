/*You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.*/

//Time Complexity -- O(logN)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n=nums.size();

        //check if the vector contains single element
        if(n==1){
            return nums[0];
        }

        //applying binary search and checking which part of the vector contains ans
        int start=0;
        int end=n-1;
        int ans=-1;
        while(start<=end){

            //check for the corner cases
            if(start==end){
                return nums[start];
            }

            int mid = start+(end-start)/2;
            if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]){
                ans=nums[mid];
                break;
            }
            else if(nums[mid]==nums[mid+1]){
                if(mid%2==0){
                    start=mid+2;
                }
                else{
                    end=mid-1;
                }
            }
            else{
                if(mid%2==0){
                    end=mid-2;
                }
                else{
                    start=mid+1;
                }
            }
        }

        //return the element
        return ans;
    }
};
