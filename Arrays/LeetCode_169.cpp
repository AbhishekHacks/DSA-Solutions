/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

*/

//Time Complexity -- O(n)

//Moore's Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        int candidate = -1;
        int count=0;

        for(int i=0;i<n;i++){
            if(count==0){
                candidate = nums[i];
            }
            if(nums[i]==candidate){
                count+=1;
            }
            else{
                count-=1;
            }
        }

        return candidate;
    }
};
