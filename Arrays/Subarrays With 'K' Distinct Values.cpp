/*You are given an array ‘ARR’ having ‘N’ integers. You are also given an integer ‘K’. The task is to count the number of subarrays that have ‘K’ distinct values.



Subarray: A consecutive sequence of one or more values taken from an array.



For Example :
‘N’ = 4, ‘K’ = 2
‘ARR’ = [1, 1, 2, 3]

There are ‘3’ subarrays with ‘2’ distinct elements, which are as follows: [1, 2], [2, 3], [1, 1, 2].
Thus, you should return ‘3’ as the answer.*/

//Time Complexity -- O(n)

int atmostkDistinctSubarrays(vector<int> &arr, int n, int k)
{
    // Write your code here
    int left = 0;
    int count=0;
    unordered_map<int,int>m;
    for(int right=0;right<n;right++){
        if(m[arr[right]]==0){
            k--;
        }
        m[arr[right]]++;
        while(k<0){
            m[arr[left]]--;
            if(m[arr[left]]==0){
                k++;
            }
            left++;
        }

        count+=right-left+1;
    }
    return count;
}

int kDistinctSubarrays(vector<int> &arr, int n, int k)
{
    // Write your code here
    return atmostkDistinctSubarrays(arr,n,k)-atmostkDistinctSubarrays(arr,n,k-1);
}
