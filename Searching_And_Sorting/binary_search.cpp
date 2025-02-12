#include <iostream>
using namespace std;

//Time Complexity -- O(logn)
int binarySearch(int arr[],int size,int key){
  int start=0;
  int end=size-1;
  while(start<=end){
    int mid = (start+end)/2;
    if(arr[mid]==key){
      return mid;
    }
    //when your key is greater than the middle element , just move the start pointer to mid+1
    else if(arr[mid]<key){
      start=mid+1;
    }
    //when your key is less than the middle element , just move the end pointer to mid-1
    else{
      end=mid-1;
    }
  }

  return -1;
}

int main(){
  int even[6]={2,4,6,8,12,18};
  int odd[5]={3,8,11,14,16};

  cout<<binarySearch(even,6,9)<<endl;
  cout<<binarySearch(odd,5,14)<<endl;

  return 0;
}
