/*Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].*/

//Time Complexity -- O(n)

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans;
        int i=0,j=n;
        bool even=true;
        while(ans.size()<2*n){
            if(even){
                ans.push_back(nums[i++]);
            }
            else{
                ans.push_back(nums[j++]);
            }
            even=!even;
        }
        return ans;
    }
};
