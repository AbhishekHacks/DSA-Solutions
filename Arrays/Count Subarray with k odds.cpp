/*You are given an array arr[] of positive integers and an integer k. You have to count the number of subarrays that contain exactly k odd numbers.*/

//Time Complexity -- O(n)

class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int>odd_index;
        for(int i=0;i<n;i++){
            if(arr[i]%2!=0){
                odd_index.push_back(i);
            }
        }
        if(odd_index.size()<k){
            return 0;
        }
        int l = odd_index.size();
        int index1 = 0;
        int index2 = k-1;
        int count_subarray = 0;
        while(index2<l){
            int left_poss,right_poss;
            if(index1==0){
                left_poss = odd_index[index1]+1;
            }
            else{
                left_poss = odd_index[index1]-odd_index[index1-1];
            }
            if(index2==l-1){
                right_poss = n-odd_index[index2];
            }
            else{
                right_poss = odd_index[index2+1]-odd_index[index2];       
            }
            count_subarray+=(left_poss*right_poss);
            index1++;
            index2++;
        }
        return count_subarray;
    }
};
