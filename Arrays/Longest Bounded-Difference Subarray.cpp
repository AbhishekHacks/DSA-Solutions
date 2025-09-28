/*Given an array of positive integers arr[] and a non-negative integer x, the task is to find the longest sub-array where the absolute difference between any two elements is not greater than x.
If multiple such subarrays exist, return the one that starts at the smallest index.*/

//Time Complexity -- O(nlogn)

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int i=0,j=0;
        map<int,int>m;
        int start,end,maximum_len=INT_MIN;
        bool i_increment = false;
        while(j<n){
            if(!i_increment){
                m[arr[j]]++;
            }
            auto it1 = m.begin();
            auto it2 = m.end();
            it2--;
            int minimum = it1->first;
            int maximum = it2->first;
            if(maximum-minimum<=x){
                int len = j-i+1;
                if(maximum_len<len){
                    maximum_len=len;
                    start=i;
                    end=j;
                }
                j++;
                i_increment=false;
            }
            else{
                m[arr[i]]--;
                if(m[arr[i]]==0){
                    m.erase(arr[i]);
                }
                i++;
                i_increment=true;
            }
        }
        vector<int>ans;
        for(int k=start;k<=end;k++){
            ans.push_back(arr[k]);
        }
        return ans;
    }
};
