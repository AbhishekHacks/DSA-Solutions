/*You are given an array nums of distinct integers.

In one operation, you can swap any two adjacent elements in the array.

An arrangement of the array is considered valid if the parity of adjacent elements alternates, meaning every pair of neighboring elements consists of one even and one odd number.

Return the minimum number of adjacent swaps required to transform nums into any valid arrangement.

If it is impossible to rearrange nums such that no two adjacent elements have the same parity, return -1.*/

//Time Complexity -- O(n)

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]=i;
        }
        vector<int>odd;
        vector<int>even;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even.push_back(nums[i]);
            }
            else{
                odd.push_back(nums[i]);
            }
        }
        if(n%2==0){
            if(even.size()!=odd.size()){
                return -1;
            }
        }
        else{
            int o = odd.size();
            int e = even.size();
            if(abs(o-e)!=1){
                return -1;
            }
        }
        int minimum = INT_MAX;
        if(even.size()>=odd.size()){
            int count1=0;
            int index1=0;
            int index2=0;
            vector<int>temp;
            for(int i=0;i<n;i++){
                if(i%2==0){
                    temp.push_back(even[index1]);
                    index1++;
                }
                else{
                    temp.push_back(odd[index2]);
                    index2++;
                }
            }
            for(int i=0;i<n;i++){
                int index = m[temp[i]];
                int diff = index-i;
                if(diff<=0){
                    diff=0;
                }
                count1+=diff;
            }
            minimum = min(minimum,count1);
        }
        if(odd.size()>=even.size()){
            int count2=0;
            int index1=0;
            int index2=0;
            vector<int>temp;
            for(int i=0;i<n;i++){
                if(i%2==0){
                    temp.push_back(odd[index1]);
                    index1++;
                }
                else{
                    temp.push_back(even[index2]);
                    index2++;
                }
            }
            for(int i=0;i<n;i++){
                int index = m[temp[i]];
                int diff = index-i;
                if(diff<=0){
                    diff=0;
                }
                count2+=diff;
            }
            minimum = min(minimum,count2);
        }
        return minimum;
    }
};
