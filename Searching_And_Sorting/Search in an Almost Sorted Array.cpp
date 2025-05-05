/*Given a sorted integer array arr[] consisting of distinct elements, where some elements of the array are moved to either of the adjacent positions, i.e. arr[i] may be present at arr[i-1] or arr[i+1].
Given an integer target.  You have to return the index ( 0-based ) of the target in the array. If target is not present return -1.*/

//Time Complexity -- O(log n)

class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        int start=0;
        int end=arr.size()-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]<target){
                if(arr[mid-1]==target){
                    return mid-1;
                }
                start=mid+1;
            }
            else{
                if(arr[mid+1]==target){
                    return mid+1;
                }
                end=mid-1;
            }
        }
        return -1;
    }
};
