/*You may recall that an array arr is a mountain array if and only if:
arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

Example 1:
Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.

Example 2:
Input: arr = [2,2,2]
Output: 0
Explanation: There is no mountain.*/

//Time Complexity -- O(n)

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if(n<3){
            return 0;
        }
        bool isMountain=false;
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]){
                isMountain=true;
                break;
            }
        }
        if(!isMountain){
            return 0;
        }
        bool left=false;
        bool right=false;
        int length=0;
        int max=0;
        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1]&&right==false){
                length++;
                left=true;
            }
            else if(arr[i]>arr[i+1]&&left==true){
                length++;
                right=true;
            }
            else{
                if(left==true&&right==true){
                    if(max<length){
                        max=length;
                    }
                    i--;
                }
                left=false;
                right=false;
                length=0;
            }
        }
        if(max<length&&left==true&&right==true){
            max=length;
        }
        return max+1;
    }
};
