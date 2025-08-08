/*Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

For i <= k < j:
arr[k] > arr[k + 1] when k is odd, and
arr[k] < arr[k + 1] when k is even.
Or, for i <= k < j:
arr[k] > arr[k + 1] when k is even, and
arr[k] < arr[k + 1] when k is odd.*/

//Time Complexity -- O(n)

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int maximum = 1;
        int i=0;
        while(i<n-1){
            if(arr[i]==arr[i+1]){
                i++;
                continue;
            }
            else if(arr[i]>arr[i+1]){
                int j = i+1;
                bool bara = true;
                while(j<n){
                    if(bara){
                        if(arr[j]<arr[j-1]){
                            bara = false;
                            j++;
                        }
                        else{
                            maximum = max(maximum,(j-i));
                            break;
                        }
                    }
                    else{
                        if(arr[j]>arr[j-1]){
                            bara = true;
                            j++;
                        }
                        else{
                            maximum = max(maximum,(j-i));
                            break;
                        }
                    }
                }
                maximum = max(maximum,(j-i));
                i=j-1;
            }
            else{
                int j = i+1;
                bool bara = false;
                while(j<n){
                    if(bara){
                        if(arr[j]<arr[j-1]){
                            bara = false;
                            j++;
                        }
                        else{
                            maximum = max(maximum,(j-i));
                            break;
                        }
                    }
                    else{
                        if(arr[j]>arr[j-1]){
                            bara = true;
                            j++;
                        }
                        else{
                            maximum = max(maximum,(j-i));
                            break;
                        }
                    }
                }
                maximum = max(maximum,(j-i));
                i=j-1;
            }
        }
        return maximum;
    }
};
