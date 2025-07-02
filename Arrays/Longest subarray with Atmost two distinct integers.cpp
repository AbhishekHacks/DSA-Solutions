/*Given an array arr[] consisting of positive integers, your task is to find the length of the longest subarray that contains at most two distinct integers.*/

//Time Complexity -- O(n)

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n  = arr.size();
        int i =0;
        int j =0;
        int maximum=INT_MIN;
        unordered_map<int,int>m;
        while(j<n){
            m[arr[j]]++;
            if(m.size()<=2){
                int len = j-i+1;
                maximum=max(maximum,len);
            }
            else{
                m[arr[i]]--;
                if(m[arr[i]]==0){
                    m.erase(arr[i]);
                }
                i++;
            }
            j++;
        }
        return maximum;
    }
};
