/*Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.*/

//Time Complexity -- O(n^2logn)

class Solution {
public:

    bool isPossible(vector<int>& nums1, vector<int>& nums2,int n1,int n2,int mid){
        map<vector<int>,int>m;
        for(int i=0;i<=n1-mid;i++){
            vector<int>vec;
            for(int j=i;j<i+mid;j++){
                vec.push_back(nums1[j]);
            }
            m[vec]++;
        }
        for(int i=0;i<=n2-mid;i++){
            vector<int>vec;
            for(int j=i;j<i+mid;j++){
                vec.push_back(nums2[j]);
            }
            if(m.count(vec)){
                return true;
            }
        }
        return false;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int start=1;
        int end=min(n1,n2);
        int answer=0;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(nums1,nums2,n1,n2,mid)){
                answer=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return answer;
    }
};
