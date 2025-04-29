/*You are given a sorted integer array 'arr' of size 'n'.



You need to remove the duplicates from the array such that each element appears only once.



Return the length of this new array.



Note:
Do not allocate extra space for another array. You need to do this by modifying the given input array in place with O(1) extra memory. 
*/

//Time Complexity -- O(n)

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.

	int count=1;
	int prev = arr[0];
	for(int i=1;i<n;i++){
		int curr = arr[i];
		if(prev==curr){
			continue;
		}
		else{
			count+=1;
		}
		prev = curr;
	}

	return count;
}
