/*You are given an integer n indicating there are n specialty retail stores. There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, where quantities[i] represents the number of products of the ith product type.

You need to distribute all products to the retail stores following these rules:

A store can only be given at most one product type but can be given any amount of it.
After distribution, each store will have been given some number of products (possibly 0). Let x represent the maximum number of products given to any store. You want x to be as small as possible, i.e., you want to minimize the maximum number of products that are given to any store.
Return the minimum possible x.*/

//Time Complexity -- O(nlogn)

class Solution {
public:

    bool isPossible(int n, vector<int> quantities,int mid){
        int totalstore=0;
        for(int i : quantities){
            totalstore+=(i + mid - 1) / mid;
        }
        return totalstore<=n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int largest=INT_MIN;
        for(int i=0;i<quantities.size();i++){
            if(largest<quantities[i]){
                largest=quantities[i];
            }
        }
        int start=1;
        int end=largest;
        int ans=0;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(n,quantities,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};
