/*You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.*/

//Time Complexity -- O(n)

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        vector<int>prefix(n,0);
        prefix[0]=arrays[0][arrays[0].size()-1];
        vector<int>suffix(n,0);
        suffix[n-1]=arrays[n-1][arrays[n-1].size()-1];
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],arrays[i][arrays[i].size()-1]);
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],arrays[i][arrays[i].size()-1]);
        }
        int maximum = INT_MIN;
        for(int i=0;i<n;i++){
            if(i==0){
                int dis = abs(suffix[1]-arrays[i][0]);
                maximum = max(maximum,dis);
            }
            else if(i==n-1){
                int dis = abs(prefix[n-2]-arrays[i][0]);
                maximum = max(maximum,dis);
            }
            else{
                int dis1 = abs(prefix[i-1]-arrays[i][0]);
                int dis2 = abs(suffix[i+1]-arrays[i][0]);
                maximum = max(maximum,dis1);
                maximum = max(maximum,dis2);
            }
        }
        return maximum;
    }
};
