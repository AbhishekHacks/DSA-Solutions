/*Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.*/

//Time Complexity -- O(log(logn))

class Solution {
public:

    bool isPossible(vector<int>& citations,int n,int mid){
        int start=0;
        int end=n-1;
        int index=-1;
        while(start<=end){
            int temp = start+(end-start)/2;
            if(citations[temp]>=mid){
                index=temp;
                end=temp-1;
            }
            else{
                start=temp+1;
            }
        }
        if(index!=-1&&n-index>=mid){
            return true;
        }
        return false;
    }

    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n = citations.size();
        int start = 0;
        int end = n;
        int answer=0;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(citations,n,mid)){
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
