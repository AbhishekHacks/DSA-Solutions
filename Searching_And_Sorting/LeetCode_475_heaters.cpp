/*Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.

Every house can be warmed, as long as the house is within the heater's warm radius range. 

Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.

Notice that all the heaters follow your radius standard, and the warm radius will the same.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    
    bool isPossible(vector<int>& houses, vector<int>& heaters,int mid){
        int i=0;
        int j=0;
        while(j<heaters.size()){
            if(abs(heaters[j]-houses[i])<=mid){
                i++;
                if(i>=houses.size()){
                    return 1;
                }
            }
            else{
                j++;
            }
        }
        return 0;
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        sort(houses.begin(),houses.end());
        int start=0;
        int end=pow(10,9);
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(houses,heaters,mid)){
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
