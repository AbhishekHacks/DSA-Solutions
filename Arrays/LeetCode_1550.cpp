/*Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.*/

//Time Complexity -- O(n)

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if(n<3){
            return false;
        }
        int count=0;
        for(int i=0;i<3;i++){
            if(arr[i]%2!=0){
                count+=1;
            }
        }
        if(count==3){
            return true;
        }
        int startIndex=0;
        for(int i=3;i<n;i++){
            if((arr[i]%2!=0)&&(arr[startIndex]%2==0)){
                count+=1;
                if(count==3){
                    return true;
                }
            }
            else if((arr[i]%2==0)&&(arr[startIndex]%2!=0)){
                count-=1;
            }
            startIndex++;
        }

        return false;
    }
};
