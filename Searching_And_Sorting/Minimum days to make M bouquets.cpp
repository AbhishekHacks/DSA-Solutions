/*You have a row of flowers, where each flower blooms after a specific day. The array arr[] represents the blooming schedule: arr[i] is the day the flower at position i will bloom. To create a bouquet, you need to collect k adjacent bloomed flowers. Each flower can only be used in one bouquet.

Your goal is to find the minimum number of days required to make exactly m bouquets. If it is not possible to make m bouquets with the given arrangement, return -1.*/

//Time Complexity -- O(nlog(maximum))

class Solution {
  public:
  
    bool isPossible(vector<int>& arr,int n, int k, int m,int mid){
        int totalBouquets = 0;
        int currflower=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=mid){
                currflower++;
                if(currflower==k){
                    totalBouquets++;
                    currflower=0;
                }
            }
        }
        if(totalBouquets>=m){
            return true;
        }
        return false;
    }
  
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        int n = arr.size();
        auto it = max_element(arr.begin(),arr.end());
        int start = 1;
        int end = *it;
        int answer=-1;
        while(start<=end){
           int mid = start+(end-start)/2;
           if(isPossible(arr,n,k,m,mid)){
               answer=mid;
               end=mid-1;
           }
           else{
               start=mid+1;
           }
        }
        return answer;
    }
};
