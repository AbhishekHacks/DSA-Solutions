//find the first and last occurrence of a target element in a sorted array , the array contains duplicate elements as well.

#include <iostream>
using namespace std;

int firstoccurrence(int arr[],int size,int target){
  int first=-1;
  int start=0;
  int end=size-1;
  while(start<=end){
    int mid = start + (end-start)/2;
    if(arr[mid]==target){
      first=mid;
      end=mid-1;
    }
    else if(arr[mid]<target){
      start=mid+1;
    }
    else{
      end=mid-1;
    }
  }
  return first;
}

int lastoccurrence(int arr[],int size,int target){
  int last=-1;
  int start=0;
  int end=size-1;
  while(start<=end){
    int mid = start + (end-start)/2;
    if(arr[mid]==target){
      last=mid;
      start=mid+1;
    }
    else if(arr[mid]<target){
      start=mid+1;
    }
    else{
      end=mid-1;
    }
  }
  return last;
}


int main(){
  int array[1000];
  int size;
  cout<<"Enter the size of the array:";
  cin>>size;
  cout<<"Enter the elements of the array:";
  for(int i=0;i<size;i++){
    cin>>array[i];
  }
  int target;
  cout<<"Enter the target element:";
  cin>>target;
  cout<<"The first occurence of "<<target<<" in the array is at index: "<<firstoccurrence(array,size,target)<<endl;
  cout<<"The last occurrence of "<<target<<" in the array is at index: "<<lastoccurrence(array,size,target);

  return 0;
}
