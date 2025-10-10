/*You are given an array arr[] of integers. Find the total count of subarrays with their sum equal to 0.*/

//Time Complexity -- O(n)

class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        int n = arr.size();
        unordered_map<int,int>m;
        vector<int>prefix(n,0);
        prefix[0]=arr[0];
        m[prefix[0]]++;
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+arr[i];
            m[prefix[i]]++;
        }
        int count=m[0];
        for(int i=0;i<n-1;i++){
            m[prefix[i]]--;
            if(m[prefix[i]]==0){
                m.erase(prefix[i]);
            }
            else{
                count+=m[prefix[i]];
            }
        }
        return count;
    }
};
