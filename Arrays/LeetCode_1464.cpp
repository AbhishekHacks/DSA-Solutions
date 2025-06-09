/*Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 */

//Time Complexity -- O(n)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int first_maximum=INT_MIN;
        int second_maximum=INT_MIN;
        for(int i=0;i<n;i++){
            if(first_maximum<nums[i]){
                int temp=first_maximum;
                first_maximum=nums[i];
                second_maximum=temp;
            }
            else{
                second_maximum=max(second_maximum,nums[i]);
            }
        }
        return (first_maximum-1)*(second_maximum-1);
    }
};
