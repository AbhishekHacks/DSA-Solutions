/*You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.

You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. Each child can be allocated candies from only one pile of candies and some piles of candies may go unused.

Return the maximum number of candies each child can get.*/

class Solution {
public:
    
    bool isPossible(vector<int>& candies, long long k,int mid){
        long long totalchildren=0;
        int i=0;
        while(i<candies.size()){
            totalchildren+=candies[i]/mid;
            if(totalchildren>=k){
                return 1;
            }
            i++;
        }
        return 0;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        int end=candies[0];
        for(int i=1;i<candies.size();i++){
            if(end<candies[i]){
                end=candies[i];
            }
        }
        int start=1;
        int answer=0;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(candies,k,mid)){
                answer=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return answer;
    }
};
