/*Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.*/

//Time Complexity -- O(n)

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int maximum = 0;
        int i=0,j=1,k=2;
        while(k<n){
            int s1 = nums[i],s2 = nums[j],s3 = nums[k];
            if(s1+s2>s3&&s1+s3>s2&&s2+s3>s1){
                maximum = max(maximum,(s1+s2+s3));
            }
            i++;j++;k++;
        }
        return maximum;
    }
};
