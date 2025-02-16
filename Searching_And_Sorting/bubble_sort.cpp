#include <iostream>
using namespace std;

void printArray(int arr[],int size){
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void bubblesort(int arr[],int size){
  for(int i=0;i<size-1;i++){
    for(int j=0;j<size-1-i;j++){
      if(arr[j]>arr[j+1]){
        //swap
        int temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }
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
  printArray(arr,size);
  cout<<"Array after Bubble Sort:";
  bubblesort(arr,size);
  printArray(arr,size);
}
