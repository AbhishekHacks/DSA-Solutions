/*Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: If it is not possible to allocate books to all students, return -1.*/

//Time Complexity -- O(nlog(sum))

class Solution {
  public:
  
    bool isPossible(vector<int> &arr, int n,int k,int mid){
        int totalStudents=0;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }
            else{
                totalStudents++;
                if(totalStudents==k){
                    return false;
                }
                sum=0;
                i--;
            }
        }
        return true;
    }
  
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k>n){
            return -1;
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        int start = 1;
        int end = sum;
        int answer = -1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(arr,n,k,mid)){
                answer = mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return answer;
    }
};
