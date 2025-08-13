/*You are given an array arr[] of size n, where arr[i] represents the number of soldiers in the i-th troop. You are also given an integer k. A troop is considered "lucky" if its number of soldiers is a multiple of k. Find the minimum total number of soldiers to add across all troops so that at least ⌈n / 2⌉ troops become lucky.*/

//Time Complexity -- O(nlogn)

class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int req = ceil(n/2.0);
        vector<int>required;
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]%k==0){
                count++;
            }
            else{
                int rem = arr[i]%k;
                required.push_back(k-rem);
            }
        } 
        if(count>=req){
            return 0;
        }
        int soldiers=0;
        sort(required.begin(),required.end());
        for(int i=0;i<req-count;i++){
            soldiers+=required[i];
        }
        return soldiers;
    }
};
