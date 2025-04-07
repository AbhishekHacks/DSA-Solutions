/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

*/

//Time Complexity -- O(N)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>answer;

        //maintain two vectors suffix and prefix and calculate that for each element
        vector<int>prefix(n,1);
        vector<int>suffix(n,1);
        
        //for prefix and suffix
        int i=0;
        int pro1=1;
        int pro2=1;
        while(i<n){
            prefix[i]=pro1;
            suffix[n-1-i]=pro2;
            pro1*=nums[i];
            pro2*=nums[n-1-i];
            i++;
        }

        for(int i=0;i<n;i++){
            int element = prefix[i]*suffix[i];
            answer.push_back(element);
        }

        return answer;
    }
};
