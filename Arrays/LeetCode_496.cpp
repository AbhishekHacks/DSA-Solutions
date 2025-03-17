/*The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

*/

//Time Complexity -- O(N)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack<int>s;
        vector<int>temp(n,-1);
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&nums2[i]>s.top()){
                s.pop();
            }
            if(!s.empty()){
                temp[i]=s.top();
            }
            s.push(nums2[i]);
        }
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums2[i]]=temp[i];
        }
        for(int i=0;i<nums1.size();i++){
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};
