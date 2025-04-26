/*You are given two positive integers 'n' and 'm'. You have to return the 'nth' root of 'm', i.e. 'm(1/n)'. If the 'nth root is not an integer, return -1.



Note:
'nth' root of an integer 'm' is a number, which, when raised to the power 'n', gives 'm' as a result.


Example:
Input: ‘n’ = 3, ‘m’ = 27

Output: 3*/

//Time Complexity -- O(n*log(m))

int NthRoot(int n, int m) {
  // Write your code here.
    int start=1;
    int end=m;
    while(start<=end){
      int mid = (start+end)/2;
      long long res=1;
      for(int i=1;i<=n;i++){
        res*=mid;
        if(res>m){
          break;
        }
      }
      if(res==m){
        return mid;
      }
      else if(res>m){
        end=mid-1;
      }
      else{
        start=mid+1;
      }
    }

    return -1;
}
