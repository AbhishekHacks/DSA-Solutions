/*Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.*/

//Time Complexity -- O(n)

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            temp.push_back(arr[i]);
        }
        int i=0;
        int j=0;
        while(j<n){
            if(temp[i]==0){
                arr[j]=0;
                if(j+1<n){
                    arr[j+1]=0;
                }
                j++;
            }
            else{
                arr[j]=temp[i];
            }
            i++;
            j++;
        }
    }
};
