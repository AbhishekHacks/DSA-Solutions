/*Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper and citations is sorted in non-descending order, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

You must write an algorithm that runs in logarithmic time.*/

//Time Complexity -- O(loglog(n))

class Solution {
public:

    bool isPossible(vector<int>&citations,int n,int mid){
        int start=0;
        int end=n-1;
        int index=-1;
        while(start<=end){
            int mid1= start+(end-start)/2;
            if(citations[mid1]>=mid){
                index = mid1;
                end=mid1-1;
            }
            else{
                start=mid1+1;
            }
        }
        if(index!=-1&&(n-index)>=mid){
            return true;
        }
        return false;
    }

    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int start = 0;
        int end = n;
        int answer=0;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(citations,n,mid)){
                answer = mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return answer;
    }
};
