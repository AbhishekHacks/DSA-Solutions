/*You are given a 0-indexed array nums of n integers, and an integer k.

The k-radius average for a subarray of nums centered at some index i with the radius k is the average of all elements in nums between the indices i - k and i + k (inclusive). If there are less than k elements before or after the index i, then the k-radius average is -1.

Build and return an array avgs of length n where avgs[i] is the k-radius average for the subarray centered at index i.

The average of x elements is the sum of the x elements divided by x, using integer division. The integer division truncates toward zero, which means losing its fractional part.

For example, the average of four elements 2, 3, 1, and 5 is (2 + 3 + 1 + 5) / 4 = 11 / 4 = 2.75, which truncates to 2.*/

//Time Complexity -- O(n)

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>prefix(n,0);
        prefix.push_back(nums[0]);
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        vector<int>answer;
        for(int i=0;i<n;i++){
            if(i-k<0||i+k>n-1){
                answer.push_back(-1);
            }
            else{
                int avg = (prefix[i+k]-prefix[i-k]+nums[i-k])/((2*k)+1);
                answer.push_back(avg);
            }
        }
        return answer;
    }
};
