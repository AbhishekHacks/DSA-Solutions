/*In the town of Digitville, there was a list of numbers called nums containing integers from 0 to n - 1. Each number was supposed to appear exactly once in the list, however, two mischievous numbers sneaked in an additional time, making the list longer than usual.

As the town detective, your task is to find these two sneaky numbers. Return an array of size two containing the two numbers (in any order), so peace can return to Digitville.*/

//Time Complexity -- O(n)

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(n-2,0);
        vector<int>answer;
        for(int i=0;i<n;i++){
            temp[nums[i]]+=1;
            if(temp[nums[i]]==2){
                answer.push_back(nums[i]);
            }
        }
        return answer;
    }
};
