/*Given an integer array nums containing n integers, find the beauty of each subarray of size k.

The beauty of a subarray is the xth smallest integer in the subarray if it is negative, or 0 if there are fewer than x negative integers.

Return an integer array containing n - k + 1 integers, which denote the beauty of the subarrays in order from the first index in the array.

A subarray is a contiguous non-empty sequence of elements within an array.*/

//Time Complexity -- O(n)

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int>answer;
        unordered_map<int,int>m;
        int negative_count = 0;
        for(int i=0;i<k;i++){
            if(nums[i]<0){
                m[nums[i]]++;
                negative_count+=1;
            }
        }
        if(negative_count<x){
            answer.push_back(0);
        }
        else{
            int low_limit = -50;
            int count=0;
            while(low_limit<0){
                if(m.count(low_limit)){
                    int freq = m[low_limit];
                    count+=freq;
                    if(x<=count){
                        answer.push_back(low_limit);
                        break;
                    }
                }
                low_limit++;
            }
        }
        int index = 0;
        for(int i=k;i<n;i++){
            if(nums[i]<0){
                m[nums[i]]++;
                negative_count+=1;
            }
            if(m.count(nums[index])){
                m[nums[index]]--;
                negative_count-=1;
                if(m[nums[index]]==0){
                    m.erase(nums[index]);
                }
            }
            if(negative_count<x){
                answer.push_back(0);
            }
            else{
                int low_limit = -50;
                int count=0;
                while(low_limit<0){
                    if(m.count(low_limit)){
                        int freq = m[low_limit];
                        count+=freq;
                        if(x<=count){
                            answer.push_back(low_limit);
                            break;
                        }
                    }
                    low_limit++;
                }
            }
            index++;
        }
        return answer;
    }
};
