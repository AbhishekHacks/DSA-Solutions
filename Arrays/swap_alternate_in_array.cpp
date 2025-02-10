#include <iostream>
using namespace std;

void printArray(int arr[],int size){
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void alternate(int arr[],int size){
  for(int i=0;i<size-1;i+=2){
    //swap
    int temp=arr[i+1];
    arr[i+1]=arr[i];
    arr[i]=temp;
  }
}

int main(){
  int array[1000];
  int size;
  cout<<"Enter the size of array:";
  cin>>size;
  cout<<"Enter the elements of array:";
  for(int i=0;i<size;i++){
    cin>>array[i];
  }
  cout<<endl;
  cout<<"Original Array:"<<endl;
  printArray(array,size);
  cout<<"Resulting Array:"<<endl;
  alternate(array,size);
  printArray(array,size);

  return 0;
}
