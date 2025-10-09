/*Given two unsorted arrays a[]  and b[], the task is to find all pairs whose sum equals x from both arrays.

Note: All pairs should be returned in increasing order of u. For eg. for two pairs (u1,v1) and (u2,v2), if u1 < u2 then (u1,v1) should be returned first else second.*/

//Time Complexity -- O(nlogn)

class Solution {
  public:
    // Function to find all pairs with given sum.
    vector<pair<int, int>> allPairs(int target, vector<int> &arr1, vector<int> &arr2) {
        // Code here
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        int n1 = arr1.size();
        int n2 = arr2.size();
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        for(int i=0;i<n1;i++){
            m1[arr1[i]]++;
        }
        for(int i=0;i<n2;i++){
            m2[arr2[i]]++;
        }
        int i=0,j=n2-1;
        vector<pair<int,int>>temp;
        while(i<n1&&j>=0){
            if(i>0&&arr1[i]==arr1[i-1]){
                i++;
                continue;
            }
            int sum = arr1[i]+arr2[j];
            if(sum==target){
                temp.push_back({arr1[i],arr2[j]});
                while(arr2[j-1]==arr2[j]){
                    j--;
                }
                j--;
                i++;
            }
            else if(sum>target){
                j--;
            }
            else{
                i++;
            }
        }
        vector<pair<int,int>>ans;
        for(int k=0;k<temp.size();k++){
            int freq = m1[temp[k].first]*m2[temp[k].second];
            for(int count=1;count<=freq;count++){
                ans.push_back({temp[k].first,temp[k].second});
            }
        }
        return ans;
    }
};
