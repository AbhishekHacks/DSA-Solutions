/*An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.

You are given a 0-indexed integer array nums of length n with one dominant element.

You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:

0 <= i < n - 1
nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.

Return the minimum index of a valid split. If no valid split exists, return -1.*/

//Time Complexity -- O(N)

class Solution {
public:
    int minimumIndex(vector<int>& nums) {

        int n=nums.size();
        
        //first up , we try to find the dominant element and the frequency
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int dominant=0;
        int frequency=0;
        for(auto i:m){
            if(i.second>(n/2)){
                dominant=i.first;
                frequency=i.second;
                break;
            }
        }

        //we will assume that the dominant element is all on the right side of the array and than we will increse the left side and if it encounters a dominant element we will decrease the frequency of dominant element from the right hand side and increase in the left and each time compare whether dominant element count in both the halves is more than the size of the halves
        int count_left=0;
        int count_right=frequency;
        for(int index=0;index<n;index++){
            if(nums[index]==dominant){
                count_left++;
                count_right--;
                int first = index+1;
                int second = n-1-index;
                if((count_left>(first/2))&&(count_right>(second/2))){
                    return index;
                }
            }
        }

        //if no index can be observed
        return -1;
    }
};
