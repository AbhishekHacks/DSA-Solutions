/*Problem statement
You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once. There is a single integer value that is present in the array twice. Your task is to find the duplicate integer value present in the array.

For example:

Consider ARR = [1, 2, 3, 4, 4], the duplicate integer value present in the array is 4. Hence, the answer is 4 in this case.
Note :
A duplicate number is always present in the given array.*/

//Time Complexity -- O(N)

int findDuplicate(vector<int> &arr) 
{
    // Write your code here

    int n=arr.size();

	//first calculate the xor of each element in the array arr
    int x=0;
    for(int i=0;i<n;i++){
        x^=arr[i];
    }

    //xor the x with all the numbers from [1-(N-1)]
    for(int i=1;i<=n-1;i++){
        x^=i;
    }

    //at the last we ware left with the duplicate integer
    return x;

}
