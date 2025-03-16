/*Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

*/

//Time Complexity -- O(nlogn)

class Solution {
public:

    bool isPossible(vector<int>& piles, int h,int mid){
        int totalhours = 0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]<=mid){
                totalhours+=1;
            }
            else{
                if(piles[i]%mid==0){
                    totalhours+=(piles[i]/mid);
                }
                else{
                    totalhours+=(piles[i]/mid)+1;
                }
            }
            if(totalhours>h){
                return false;
            }
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int largest=INT_MIN;
        for(int i=0;i<piles.size();i++){
            if(largest<piles[i]){
                largest=piles[i];
            }
        }
        int start=1;
        int end=largest;
        int ans=0;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(piles,h,mid)){
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
