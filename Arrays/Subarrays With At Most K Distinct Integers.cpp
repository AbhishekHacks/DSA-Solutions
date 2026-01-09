/*You are given an array arr[] of positive integers and an integer k, find the number of subarrays in arr[] where the count of distinct integers is at most k.

Note: A subarray is a contiguous part of an array.*/

//Time Complexity -- O(n)

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int,int>m;
        int i=0,j=0,count=0;
        while(j<n){
            if(m.size()==k&&!m.count(arr[j])){
                count+=(j-i);
                m[arr[i]]--;
                if(m[arr[i]]==0){
                    m.erase(arr[i]);
                }
                i++;
            }
            else{
                m[arr[j]]++;
                j++;
            }
        }
        count+=((j-i)*(j-i+1))/2;
        return count;
    }
};
