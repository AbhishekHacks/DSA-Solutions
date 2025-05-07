/*Given a sorted array arr[] that represents an Arithmetic Progression (AP) with exactly one missing element, find the missing number.

Note: An element will always exist that, upon inserting into a sequence forms Arithmetic progression. If the given sequence already forms a valid complete AP, return the (n+1)-th element that would come next in the sequence.*/

//Time Complexity -- O(n)

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int d = arr[1]-arr[0];
        for(int i=2;i<arr.size();i++){
            if((arr[i]-arr[i-1])!=d){
                d=-1;
                break;
            }
        }
        if(d==-1){
            d = (arr[arr.size()-1]-arr[0])/arr.size();   
        }
        int next = arr[0]+d;
        for(int i = 1;i<arr.size();i++){
            if(arr[i]!=next){
                return next;
            }
            next+=d;
        }
        return next;
    }
};
