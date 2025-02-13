/*Given an array of integers arr, return true if and only if it is a valid mountain array.*/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int step=0;
        int index=-1;
        for(int i=0;i<arr.size()-1;i++){
          if(step==0){
            if(i==0&&arr[i]>=arr[i+1]){
              return 0;
            }
            if(arr[i]==arr[i+1]){
              return 0;
            }
            if(arr[i]>arr[i+1]){
              index=i;
              step=1;
            }
          }
          else{
            if(arr[i]<=arr[i+1]){
              return 0;
            }
          }
        }
      if(index==-1){
        return 0;
      }
      return 1;
    }
};
