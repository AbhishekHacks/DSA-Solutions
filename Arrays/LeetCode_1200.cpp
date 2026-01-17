/*Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        int minimum = INT_MAX;
        for(int i=0;i<n-1;i++){
            minimum = min(minimum,(arr[i+1]-arr[i]));
        }
        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i]==minimum){
                vector<int>temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[i+1]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
