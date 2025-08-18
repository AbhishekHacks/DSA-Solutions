/*You are given an array citations[], where each element citations[i] represents the number of citations received by the ith paper of a researcher. You have to calculate the researcher’s H-index.
The H-index is defined as the maximum value H, such that the researcher has published at least H papers, and all those papers have citation value greater than or equal to H.*/

//Time Complexity -- O(nlogn)

class Solution {
  public:
  
    bool isPossible(vector<int>& citations,int n ,int mid){
        int count = 0;
        for(int i=0;i<n;i++){
            if(citations[i]>=mid){
                count++;
                if(count>=mid){
                    return true;
                }
            }
        }
        return false;
    }
  
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();
        int start = 0;
        int end = n;
        int answer=0;
        while(start<=end){
            int mid  = start+(end-start)/2;
            if(isPossible(citations,n,mid)){
                answer = mid;
                start = mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return answer;
    }
};
