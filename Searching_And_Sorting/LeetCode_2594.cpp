/*You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.

You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.

Return the minimum time taken to repair all the cars.

Note: All the mechanics can repair the cars simultaneously.*/

//Time Complexity -- O(nlogn)

class Solution {
public:

    bool isPossible(vector<int>& ranks, int cars, long long mid){
        long long totalcar=0;
        for(int i=0;i<ranks.size();i++){
            long long div = mid/ranks[i];
            totalcar+=pow(div,0.5);
            if(totalcar>=cars){
                return true;
            }
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        //Time Complexity -- O(nlogn)
        sort(ranks.begin(),ranks.end());
        long long start=0;
        long long end=pow(cars,2)*ranks[0];
        long long ans=0;
        while(start<=end){
            long long mid = start+(end-start)/2;
            if(isPossible(ranks,cars,mid)){
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
