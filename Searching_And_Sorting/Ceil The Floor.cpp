/*You're given a sorted array 'a' of 'n' integers and an integer 'x'.



Find the floor and ceiling of 'x' in 'a[0..n-1]'.



Note:
Floor of 'x' is the largest element in the array which is smaller than or equal to 'x'.
Ceiling of 'x' is the smallest element in the array greater than or equal to 'x'.
*/

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.

	int floor=-1;
	int ceil=-1;

	int start = 0;
	int end = n-1;
	while(start<=end){
		int mid = start+(end-start)/2;
		if(a[mid]<=x){
			floor = a[mid];
			start = mid+1;
		}
		else{
			end = mid-1;
		}
	}

	start=0;
	end = n-1;
	while(start<=end){
		int mid = start+(end-start)/2;
		if(a[mid]>=x){
			ceil = a[mid];
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}

	pair<int,int>p;
	p.first = floor;
	p.second = ceil;
	return p;
}
