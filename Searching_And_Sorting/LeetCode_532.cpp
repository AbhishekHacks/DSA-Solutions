/*Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.*/

//Time Complexity -- O(NlogN)

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        int n=nums.size();
        
        //sort the vector
        sort(nums.begin(),nums.end());

        //declare a variable for storing the count of unique pairs
        int count=0;

        //applying binary search over all the elements
        for(int i=0;i<n;i++){
            if(i==0||nums[i]!=nums[i-1]){
                int key = k+nums[i];
                int start=i+1;
                int end=n-1;
                while(start<=end){
                    int mid = start+(end-start)/2;
                    if(nums[mid]==key){
                        count+=1;
                        break;
                    }
                    else if(nums[mid]>key){
                        end=mid-1;
                    }
                    else{
                        start=mid+1;
                    }
                }
            }
        }

        //return the count of unique pairs
        return count;
    }
};
