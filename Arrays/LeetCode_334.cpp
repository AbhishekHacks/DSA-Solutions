/*Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.*/

//Time Complexity -- O(n)

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();

        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        int smallest=nums[0];
        int largest=nums[n-1];
    
        for(int i=1;i<n-1;i++){
            smallest=min(smallest,nums[i-1]);
            prefix[i]=smallest;
            largest=max(largest,nums[n-i]);
            suffix[n-1-i]=largest;  
        }

        for(int i=1;i<n-1;i++){
            if(nums[i]>prefix[i]&&nums[i]<suffix[i]){
                return true;
            }
        }

        return false;
    }
};
