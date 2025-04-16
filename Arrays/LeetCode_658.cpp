/*Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n = arr.size();
        vector<int> closestelements;
        int closestelementindex=-1;
        int minimum = INT_MAX;

        //find closest element index to x
        for(int i=0;i<n;i++){
            int diff = abs(arr[i]-x);
            if(diff<minimum){
                minimum=diff;
                closestelementindex=i;
            }
        }

        closestelements.push_back(arr[closestelementindex]);

        if(k==1){
            return closestelements;
        }

        //now since we got the closest element index we take two pointers but first lets include the closest element
        int i=closestelementindex-1;
        int j=closestelementindex+1;
        while(i>=0&&j<n){
            int diff1= abs(arr[i]-x);
            int diff2= abs(arr[j]-x);
            if(diff1<=diff2){
                closestelements.push_back(arr[i]);
                i--;
            }
            else{
                closestelements.push_back(arr[j]);
                j++;
            }
            if(closestelements.size()==k){
                break;
            }
        }

        while(closestelements.size()<k&&i>=0){
            closestelements.push_back(arr[i]);
            i--;
        }

        while(closestelements.size()<k&&j<n){
            closestelements.push_back(arr[j]);
            j++;
        }

        //lastly sort the array once
        sort(closestelements.begin(),closestelements.end());

        return closestelements;
    }
};
