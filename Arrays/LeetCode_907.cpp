/*Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.*/

//Time Complexity -- O(n)

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1000000007;
        vector<int>previous_smaller(n,-1);
        vector<int>next_smaller(n,n);
        stack<pair<int,int>>prev_small;
        stack<pair<int,int>>next_small;
        for(int i=0;i<n;i++){
            while(!prev_small.empty()&&arr[i]<=prev_small.top().first){
                prev_small.pop();
            }
            if(prev_small.empty()){
                prev_small.push({arr[i],i});
            }
            else{
                previous_smaller[i]=prev_small.top().second;
                prev_small.push({arr[i],i});
            }
        }
        for(int i=n-1;i>=0;i--){
            while(!next_small.empty()&&arr[i]<next_small.top().first){
                next_small.pop();
            }
            if(next_small.empty()){
                next_small.push({arr[i],i});
            }
            else{
                next_smaller[i]=next_small.top().second;
                next_small.push({arr[i],i});
            }
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            sum=(sum+((long long)arr[i]*(i-previous_smaller[i])*(next_smaller[i]-i))%MOD)%MOD;
        }
        return sum;
    }
};
