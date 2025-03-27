/*Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.

*/

//Time Complexity -- O(n+m)

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();

        //lets take two hashmaps one for nums1 and other for nums2
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;

        //nums1
        for(int i=0;i<n;i++){
            m1[nums1[i]]++;
        }

        //nums2
        for(int i=0;i<m;i++){
            m2[nums2[i]]++;
        }

        //take two list one for nums1 and other for nums2
        vector<int>list1;
        vector<int>list2;

        //take the resultant 2D list
        vector<vector<int>> result;

        //nums1
        for(auto i:m1){
            if(!m2.count(i.first)){
                list1.push_back(i.first);
            }
        }

        //nums2
        for(auto i:m2){
            if(!m1.count(i.first)){
                list2.push_back(i.first);
            }
        }

        //insert both the lists in resultant 2D vector
        result.push_back(list1);
        result.push_back(list2);

        //return the resultant 2D vector
        return result;
    }
};
