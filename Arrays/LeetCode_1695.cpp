/*You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).*/

//Time Complexity -- O(N)

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0;
        int maximum = INT_MIN;
        int n = nums.size();
        unordered_map<int,int>m;
        int i=0;
        int j=0;
        while(j<n){
            if(!m.count(nums[j])){
                sum+=nums[j];
                m[nums[j]]=j;
            }
            else{
                int temp = m[nums[j]];
                for(int index=i;index<=temp;index++){
                    sum-=nums[index];
                    m.erase(nums[index]);
                }
                i=temp+1;
                j--;
            }
            maximum = max(maximum,sum);
            j++;
        }
        return maximum;
    }
};
