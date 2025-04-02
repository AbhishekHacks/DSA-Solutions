/*You are given a positive integer ‘n’.



Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).*/

//Time Complexity -- O(logn)

int floorSqrt(int n)
{
    // Write your code here.

    int start=0;
    int end=n;
    int ans=0;
    while(start<=end){
        int mid= start+(end-start)/2;
        long long sq = (long long)mid*mid;
        if(sq==n){
            return mid;
        }
        else if(sq<n){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }

    }

    //return the answer
    return ans;
}
