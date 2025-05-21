/*You are given an array nums of distinct positive integers. You need to sort the array in increasing order based on the sum of the digits of each number. If two numbers have the same digit sum, the smaller number appears first in the sorted order.

Return the minimum number of swaps required to rearrange nums into this sorted order.

A swap is defined as exchanging the values at two distinct positions in the array.

*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]=i;
        }
        vector<vector<int>>sorted;
        for(int i=0;i<n;i++){
            vector<int>temp;
            temp.push_back(nums[i]);
            int element = nums[i];
            int sum=0;
            while(element>0){
                int r = element%10;
                sum+=r;
                element/=10;
            }
            temp.push_back(sum);
            sorted.push_back(temp);
        }
        sort(sorted.begin(),sorted.end(),[](const vector<int>&a, vector<int>&b){
            if(a[1]==b[1]){
                return a[0]<b[0];
            }
            return a[1]<b[1];
        });
        vector<int>comp;
        for(int i=0;i<n;i++){
            int number = sorted[i][0];
            comp.push_back(number);
        }
        //swap
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=comp[i]){
                int index = m[comp[i]];
                m[nums[i]]=index;
                swap(nums[i],nums[index]);
                count+=1;
            }
        }
        return count;
    }
};
