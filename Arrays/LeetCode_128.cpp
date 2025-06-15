/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.*/

//Time Complexity -- O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        unordered_map<int,int>m;
        unordered_map<int,int>temp;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int maxlength=1;
        for(int i=0;i<nums.size();i++){
            if(temp.count(nums[i])==0){
                int countleft=0;
                int countright=0;
                int left = nums[i]-1;
                int right = nums[i]+1;
                while(m.count(left)){
                    countleft+=1;
                    temp[left]++;
                    left--;
                }
                while(m.count(right)){
                    countright+=1;
                    temp[right]++;
                    right++;
                }
                maxlength = max(maxlength,(countleft+countright+1));
            }
        }
        return maxlength;
    }
};
