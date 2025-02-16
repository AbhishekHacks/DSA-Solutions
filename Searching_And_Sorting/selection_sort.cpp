#include<iostream>
#include<cmath>
using namespace std;

void selectionsort(int arr[],int size){
  for(int i=0;i<size-1;i++){
    int minimum=arr[i];
    int index=i;
    for(int j=i+1;j<size;j++){
      if(minimum>arr[j]){
        minimum=arr[j];
        index=j;
      }
    }
    //swap
    int temp = arr[i];
    arr[i]=minimum;
    arr[index]=temp;
  }
}
int main(){
  int arr[100];
  int size;
  cout<<"Enter the size of the array:";
  cin>>size;
  cout<<"Enter the elements of the array:";
  for(int i=0;i<size;i++){
    cin>>arr[i];
  }
  cout<<"Original Array:";
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  cout<<"Array after Selection Sort:";
  selectionsort(arr,size);
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
}
