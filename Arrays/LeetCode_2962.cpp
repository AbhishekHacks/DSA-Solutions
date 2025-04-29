/*You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.

*/

//Time Complexity -- O(n)

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int n =nums.size();

        int maximum = INT_MIN;
        for(int i=0;i<n;i++){
            maximum=max(maximum,nums[i]);
        }

        long long answer=0;

        vector<int>index_of_maximum;
        for(int i=0;i<n;i++){
            if(nums[i]==maximum){
                index_of_maximum.push_back(i);
            }
        }

        if(k>index_of_maximum.size()){
            return 0;
        }

        int startIndex=0;
        for(int i=0;i<n;i++){
            if(startIndex+k-1>=index_of_maximum.size()){
                break;
            }
            int next_index = index_of_maximum[startIndex+k-1];
            answer+=(n-next_index);
            if(i==index_of_maximum[startIndex]){
                startIndex++;
            }
        }

        return answer;
    }
};
