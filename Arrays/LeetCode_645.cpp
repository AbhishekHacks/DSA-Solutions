/*You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 */

//Time Complexity -- O(n)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xor_all = 0;
        for(int i=0;i<n;i++){
            xor_all^=nums[i];
        }
        for(int i=1;i<=n;i++){
            xor_all^=i;
        }
        int difference_bit = xor_all&(-xor_all);
        int xor_x=0;
        int xor_y=0;
        for(int i=0;i<n;i++){
            if((nums[i]&difference_bit)!=0){
                xor_x^=nums[i];
            }
            else{
                xor_y^=nums[i];
            }
        }
        for(int i=1;i<=n;i++){
            if((i&difference_bit)!=0){
                xor_x^=i;
            }
            else{
                xor_y^=i;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]==xor_x){
                ans.push_back(xor_x);
                ans.push_back(xor_y);
                break;
            }
            else if(nums[i]==xor_y){
                ans.push_back(xor_y);
                ans.push_back(xor_x);
                break;
            }
        }
        return ans;
    }
};
