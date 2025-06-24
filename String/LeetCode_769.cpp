/*You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.*/

//Time Complexity -- O(n^2logn)

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            temp.push_back(arr[i]);
        }
        sort(temp.begin(),temp.end());
        string s1;
        string s2;
        int partitions=0;
        for(int i=0;i<n;i++){
            s1.push_back(arr[i]);
            s2.push_back(temp[i]);
            sort(s1.begin(),s1.end());
            if(s1==s2){
                partitions+=1;
            }
        }
        return partitions;
    }
};
