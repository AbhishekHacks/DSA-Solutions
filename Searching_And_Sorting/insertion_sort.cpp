#include <iostream>
using namespace std;

void printArray(int arr[],int size){
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void insertionsort(int arr[],int size){
  for(int i=1;i<size;i++){
    int temp=arr[i];
    int j;
    for(j=i-1;j>=0;j--){
      if(temp<arr[j]){
        arr[j+1]=arr[j];
      }
      else{
        break;
      }
    }
    arr[j+1]=temp;
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
  insertionsort(arr,size);
  printArray(arr,size);
}
