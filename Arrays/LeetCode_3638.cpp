/*You are given an integer array weight of length n, representing the weights of n parcels arranged in a straight line. A shipment is defined as a contiguous subarray of parcels. A shipment is considered balanced if the weight of the last parcel is strictly less than the maximum weight among all parcels in that shipment.

Select a set of non-overlapping, contiguous, balanced shipments such that each parcel appears in at most one shipment (parcels may remain unshipped).

Return the maximum possible number of balanced shipments that can be formed.*/

//Time Complexity -- O(N)

class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int maximum = weight[0];
        int count = 0;
        for(int i=1;i<n;i++){
            if(weight[i]<maximum){
                count+=1;
                if(i+1<n){
                    maximum = weight[i+1];
                }
                i++;
            }
            else{
                maximum = max(maximum,weight[i]);
            }
        }
        return count;
    }
};
