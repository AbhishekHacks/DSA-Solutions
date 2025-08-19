/*You are given an array arr[]. For each element at index i (0-based indexing), find the farthest index j to the right (i.e., j > i) such that arr[j] < arr[i]. If no such index exists for a given position, return -1 for that index. Return the resulting array of answers.*/

//Time Complexity -- O(nlogn)

class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>>array_2D;
        for(int i=0;i<n;i++){
            vector<int>temp;
            temp.push_back(arr[i]);
            temp.push_back(i);
            array_2D.push_back(temp);
        }
        sort(array_2D.begin(),array_2D.end(),[](const vector<int>&a,vector<int>&b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        });
        vector<int>result(n,-1);
        int maximum = array_2D[0][1];
        for(int i=1;i<n;i++){
            if(maximum>array_2D[i][1]){
                result[array_2D[i][1]]=maximum;
            }
            maximum = max(maximum,array_2D[i][1]);
        }
        return result;
    }
};
