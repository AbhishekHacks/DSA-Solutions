/*Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 109 + 7.*/

//Time Complexity -- O(n)

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int>prefix_sum;
        vector<int>even;
        vector<int>odd;
        int count_even = 0, count_odd = 0, sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            prefix_sum.push_back(sum);
            if(sum%2==0){
                count_even++;
            }
            else{
                count_odd++;
            }
            even.push_back(count_even);
            odd.push_back(count_odd);
        }
        long long count = count_odd;
        for(int i=0;i<n;i++){
            if(prefix_sum[i]%2!=0){
                count=(count+(count_even-even[i]))%1000000007;
            }
            else{
                count=(count+(count_odd-odd[i]))%1000000007;
            }
        }
        return count;
    }
};
