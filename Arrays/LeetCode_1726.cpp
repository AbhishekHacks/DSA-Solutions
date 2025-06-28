/*Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.*/

//Time Complexity -- O(n^2)

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int pro = nums[i]*nums[j];
                m[pro]++;
            }
        }
        int count=0;
        for(auto i:m){
            int total = (i.second*(i.second-1))/2;
            count+=(total*8);
        }
        return count;
    }
};
