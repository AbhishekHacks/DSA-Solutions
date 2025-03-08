/*Given an integer array nums, find three numbers whose product is maximum and return the maximum product.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(nums[n-1]==0){
            return 0;
        }
        else if(nums[n-1]<0){
            long long product = (long long)nums[n-1]*nums[n-2]*nums[n-3];
            return product;
        }
        else{
            long long product1=(long long)nums[0]*nums[1]*nums[n-1];
            long long product2=(long long)nums[0]*nums[n-1]*nums[n-2];
            long long product3=(long long)nums[n-1]*nums[n-2]*nums[n-3];
            long long max1 = max(product1,product2);
            long long finalmax = max(max1,product3);
            return finalmax;
        }
    }
};
