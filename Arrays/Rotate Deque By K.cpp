/*You are given a deque dq[] (double-ended queue) containing non-negative integers, along with two positive integer type and k. The task is to rotate the deque circularly by k positions.
There are two types of rotation operations:


Right Rotation (Clockwise): If type = 1, rotate the deque to the right. This means moving the last element to the front, and repeating the process k times.

Left Rotation (Anti-Clockwise): If type = 2, rotate the deque to the left. This means moving the first element to the back, and repeating the process k times.*/

//Time Complexity -- O(n)

class Solution {
  public:
  
    void reversing(deque<int>&dq,int i,int j){
        while(i<j){
            swap(dq[i],dq[j]);
            i++;
            j--;
        }
    }
  
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        int n = dq.size();
        k=k%n;
        if(type==1){
            reversing(dq,0,n-1-k);
            reversing(dq,n-k,n-1);
            reversing(dq,0,n-1);
        }
        else{
            reversing(dq,0,k-1);
            reversing(dq,k,n-1);
            reversing(dq,0,n-1);
        }
    }
};
