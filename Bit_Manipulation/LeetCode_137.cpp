/*Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.*/

//Time Complexity -- O(n)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int n=nums.size();
        long long answer=0;

        for(int i=0;i<32;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if((nums[j]&1)==1){
                    count++;
                }
                nums[j]=nums[j]>>1;
            }
            if(count%3!=0){
                answer+=pow(2,i);
            }
        }

        return answer;
    }
};
