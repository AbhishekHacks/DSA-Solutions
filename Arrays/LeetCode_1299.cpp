/*Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.*/

//Time Complexity -- O(n)

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int>suffix;
        int n = arr.size();
        int maximum=-1;
        for(int i=n-1;i>=0;i--){
            suffix.push_back(maximum);
            maximum=max(maximum,arr[i]);
        }
        reverse(suffix.begin(),suffix.end());
        return suffix;
    }
};
