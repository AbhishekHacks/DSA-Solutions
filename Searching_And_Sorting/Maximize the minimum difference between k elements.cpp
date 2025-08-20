/*Given an array arr[] of integers and an integer k, select k elements from the array such that the minimum absolute difference between any two of the selected elements is maximized. Return this maximum possible minimum difference.*/

//Time Complexity -- O(nlog(maximum-minimum))

class Solution {
  public:
  
    bool isPossible(vector<int>& arr, int n,int k,int mid){ //O(n)
        int count=1;
        int prev = arr[0];
        for(int i=1;i<n;i++){
            int curr = arr[i];
            if((curr-prev)>=mid){
                count++;
                if(count>=k){
                    return true;
                }
                prev = curr;
            }
        }
        return false;
    }
  
    int maxMinDiff(vector<int>& arr, int k) {
        // code here
        //Time Complexity -- O(nlog(maximum-minimum))
        sort(arr.begin(),arr.end());  //nlogn
        int n = arr.size();
        int maximum = INT_MIN;
        int minimum = INT_MAX;
        for(int i=0;i<n;i++){ //n
            maximum = max(maximum,arr[i]);
            minimum = min(minimum,arr[i]);
        }
        int start = 0;
        int end = maximum - minimum;
        int answer = 0;
        while(start<=end){ // nlog(maximum-minimum)
            int mid = start + (end-start)/2;
            if(isPossible(arr,n,k,mid)){
                answer = mid;
                start = mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return answer;
    }
};
