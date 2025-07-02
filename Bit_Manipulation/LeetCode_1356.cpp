/*You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans;
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            int count=0;
            int num = arr[i];
            while(num>0){
                if((num&1)==1){
                    count++;
                }
                num=num>>1;
            }
            pair<int,int>p;
            p.first=count;
            p.second=arr[i];
            vec.push_back(p);
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<n;i++){
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};
